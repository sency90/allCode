#include "commonHeader.h"
#include "topic.h"
#include <sys/poll.h>
//#define NUMPOLL 50
//#define LIMIT_FD 5

struct pollfd pollfds[CLI_NUM];

//참고로 tBox안에 clientInfo struct가 선언되어 있다.
TopicBox tBox[TBOX_NUM + 1];
int n_pub_all = 0;
int n_sub[TBOX_NUM + 1] = {0};

char readBuffer[BUFFER_SIZE];
char writeBuffer[BUFFER_SIZE];

void err_quit(const char* str) {
    perror(str);
    exit(1);
}

void reapPollfds(int connfd) {
    for(int i=0; i<CLI_NUM; i++) {
        if(pollfds[i].fd == connfd) {
            pollfds[i].fd = -1;
            pollfds[i].events = 0;
            pollfds[i].revents = 0;
            break;
        }
    }

    for(int i=1; i<=TBOX_NUM; i++) {
        if(tBox[i].clientId.pubfd == connfd) {
            tBox[i].clientId.pubfd = -1;
            n_pub_all--;
            break;
        }
        for(int j=0; j<SUB_NUM; j++) {
            if(tBox[i].clientId.subfd[j] == connfd) {
                tBox[i].clientId.subfd[j] = -1;
                n_sub[i]--;
                break;
            }
        }
    }

    for(int i=1; i<=TBOX_NUM; i++) {
        if(tBox[i].clientId.pubfd == -1) {
            tBox[i].isActivePub = false;
        }
    }
}

bool regiTopic(int connfd, int* tBoxNum) {
    int n;
    bool hasErr = false;
    char topicBoxNum[TBOXNUM_INDEX_SIZE];
    int kindOfChar;

    if((n = readvn(connfd, readBuffer, BUFFER_SIZE)) == 0) {
        err("invalid kindOfChar");
        hasErr = true;
    }
    readBuffer[n] = '\0';
    kindOfChar = atoi(readBuffer);

    if((n = readvn(connfd, topicBoxNum, TBOXNUM_INDEX_SIZE)) == 0) {
        err("invalid topicBoxNum");
        hasErr = true;
    }
    topicBoxNum[n] = '\0';

    *tBoxNum = atoi(topicBoxNum);

    //if tBoxNum is valid
    if((*tBoxNum) == 1 || (*tBoxNum) == 2 || (*tBoxNum) == 3) {
        //변경되기전 tBox[*topicBox]를 저장한다. (에러가 발생하면 다시 원상태로 되돌린다.)
        TopicBox origTBox = tBox[*tBoxNum];

        //요청받은 tBoxNum에 해당하는 tBox를 active 시킨다.
        //tBox[*tBoxNum].isActive = true;

        //Publisher가 topic 등록을 요청했다면,
        if(kindOfChar == PUB) {
            if(tBox[*tBoxNum].clientId.pubfd == -1 || tBox[*tBoxNum].clientId.pubfd == connfd) {
                tBox[*tBoxNum].isActivePub = true;
                tBox[*tBoxNum].clientId.pubfd = connfd;
                n_pub_all++;
            }
            else {
                hasErr = true;
                err("this topic has already been registered by another publisher");
                tBox[*tBoxNum] = origTBox;
            }
        }
        //subscriber가 topic 등록을 요청했다면,
        else if(kindOfChar == SUB) {
            int i; //for for-loop index
            for(i=0; i<SUB_NUM; i++) {
                if(tBox[*tBoxNum].clientId.subfd[i] == -1 || tBox[*tBoxNum].clientId.subfd[i] == connfd) {
                    tBox[*tBoxNum].clientId.subfd[i] = connfd;
                    n_sub[*tBoxNum]++;
                    break;
                }
            }
            //바로 위에서 for 반복문을 모두 돌았는데도 subfd가 -1인 애들이 없다면,
            if(i == SUB_NUM+1) {
                hasErr = true;
                err("There are too many subscribers.");
                tBox[*tBoxNum] = origTBox;
            }
        }
        else {
            hasErr = true;
            err("invalid kindOfClient");
            tBox[*tBoxNum] = origTBox;
        }
    }
    else {
        hasErr = true;
        err("invalid tBoxNum");
    }

    return !hasErr;
}

void recvMsg(int connfd, int *tBoxNum) {
    int n;

    if( (n = readvn(connfd, readBuffer, BUFFER_SIZE)) == 0 ) {
        err("read nothing about 'TopicBox.clientInfo.tBoxNum'");
        err("connection lost");
        close(connfd);
        reapPollfds(connfd);
    } else {
        readBuffer[n] = '\0';
        *tBoxNum = atoi(readBuffer);
    }

    //read a msg
    if( (n = readvn(connfd, readBuffer, BUFFER_SIZE)) == 0 ) {
        printf("[[AN EMPTY MESSAGE WAS RECEIVED]]!!\n");
        tBox[*tBoxNum].hasMsg = false;
    } else {
        tBox[*tBoxNum].hasMsg = true;
        readBuffer[n] = '\0';
        strcpy(tBox[*tBoxNum].tMsg.msg, readBuffer);
    }

    //read a time stamp
    if( (n = readvn(connfd, readBuffer, BUFFER_SIZE)) == 0 ) {
        err("read nothing about 'TopicMsg.timeInfo'.");
        err("connection lost");
        close(connfd);
        reapPollfds(connfd);
    } else {
        readBuffer[n] = '\0';
        strcpy(tBox[*tBoxNum].tMsg.timeInfo, readBuffer);
    }
}

void forwardMsg(int connfd, int tBoxNum) {
    strcpy(writeBuffer, tBox[tBoxNum].tMsg.msg);
    writevn(connfd, writeBuffer, strlen(writeBuffer));

    strcpy(writeBuffer, tBox[tBoxNum].tMsg.timeInfo);
    writevn(connfd, writeBuffer, strlen(writeBuffer));
}

int main(int argc, char **argv) {
    int i, j, n, listenfd, connfd;
    int nready = 0;
    ssize_t n_message;
    ssize_t n_id;

    //NUMPOLL 개수만큼 id저장 가능, 각각의 ID size는 ID_SIZE 크기를 넘지 못함.
    char line[BUFFER_SIZE];

    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    for(i=0; i<=TBOX_NUM; i++) {
        initTopicBox(&tBox[i]);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    bind(listenfd, (sockaddr*)&servaddr, sizeof(servaddr));
    listen(listenfd, LISTENQ);

    //maxfd = listenfd; //initialize
    //maxi = -1; //index into client[] array

    pollfds[0].fd = listenfd;
    pollfds[0].events = POLLIN;
    pollfds[0].revents = 0;
    for(i=1; i <= CLI_NUM; i++) {
        pollfds[i].fd = -1;
        pollfds[i].revents = 0;
    }

    int tBoxNum;
    while(1) {
        if((nready = poll(pollfds, CLI_NUM, -1)) < 0) {
            perror("poll failed");
            exit(3);
        }

        /* 1 */
        //accepting clients which requested to connect to this server
        if(pollfds[0].revents == POLLIN) { //request connection from new client
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (sockaddr*)&cliaddr, &clilen);
            printf("Connection complete!\n");
            //n_conn++;

            //char kindOfChar[TBOXNUM_INDEX_SIZE];
            //int tBoxNum;

            //regiTopic이 성공한 경우
            if(regiTopic(connfd, &tBoxNum)) {
                for(int k=1; k<=CLI_NUM; k++) {
                    if(pollfds[k].fd == -1) {
                        pollfds[k].fd = connfd;
                        pollfds[k].events = POLLIN;
                        pollfds[k].revents = 0;
                        break;
                    }
                }
                //regiTopic이 성공하면 해당 connfd 자체를 client의 ID로 부여한다.
                //char temp_fd[FD_INDEX_SIZE];
                //sprintf(temp_fd, "%d", connfd);
                sprintf(writeBuffer, "%d", connfd);
                writevn(connfd, writeBuffer, strlen(writeBuffer));
                //writevn(connfd, temp_fd, sizeof(temp_fd));
            }
            //regiTopic이 실패한 경우, 요청한 해당 클라이언트와 아예 연결을 끊어버린다.
            else {
                err("regiTopic failed");
                char err_fd[FD_INDEX_SIZE];
                sprintf(err_fd, "%d", -1);
                writevn(connfd, err_fd, sizeof(err_fd));
                close(connfd);
            }

            if(--nready <= 0) continue;
        }

        /* 2 */
        //receive and send a msg
        for(i=1; i<CLI_NUM; i++) {
            //first: receive a msg
            //printf("%d\n", maxi);
            switch(pollfds[i].revents) {
                case 0:
                    break; //no events
                case POLLIN:
                    recvMsg(pollfds[i].fd, &tBoxNum);
                    break;
                default:
                    err("invalid revents");
                    close(pollfds[i].fd);
                    reapPollfds(pollfds[i].fd);
                    //pollfds[i].fd = -1;
                    //pollfds[i].revents = 0;

                    /*
                       for(int j=1; j<=TBOX_NUM; j++) {
                       if(tBox[j].clientId.pubfd == connfd) {
                       tBox[j].clientId.pubfd = -1;
                       }
                       }
                       */
                    break;
            }

            //second: send a msg
            //message가 publish되지 않았으면 subscribe하지 않는다.
            if(tBox[tBoxNum].hasMsg && tBox[tBoxNum].isActivePub) {
                for(j=0; j<SUB_NUM; j++) {
                    if(tBox[tBoxNum].clientId.subfd[j] != -1) {
                        forwardMsg(tBox[tBoxNum].clientId.subfd[j], tBoxNum);
                    }
                }
            }

            //////////////////////////
            if(--nready <= 0) break;
        }
    }
}
