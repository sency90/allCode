//문제 < a >
//최대 3개의 publisher와 각 publisher당 3개의 subscriber가 접속할 수 있는 broker이다.

#include "commonHeader.h"
#include "topic.h"
#include <sys/poll.h>

struct pollfd pollfds[CLI_NUM];

//문제 < c-iv >
//TopicBox 구조체변수인 tBox가 topic message를 담을 저장공간이다.
//각 topic message마다 저장하기 위해서 배열로 선언하였다.
TopicBox tBox[TBOX_NUM + 1];

int n_pub_all = 0;
int n_sub[TBOX_NUM + 1] = {0};

char readBuffer[BUFFER_SIZE];
char writeBuffer[BUFFER_SIZE];

bool isPub;

void err_quit(const char* str) {
    perror(str);
    exit(1);
}

void reapPollfds(int connfd) {
    for(int i=0; i<CLI_NUM; i++) {
        if(pollfds[i].fd == connfd) {
            pollfds[i].fd = -1;
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
        for(int j=1; j<=SUB_NUM; j++) {
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

        //Publisher가 topic 등록을 요청했다면,
        if(kindOfChar == PUB) {
            if(tBox[*tBoxNum].clientId.pubfd == -1) {
                tBox[*tBoxNum].isActivePub = true;
                tBox[*tBoxNum].clientId.pubfd = connfd;
                n_pub_all++;
                isPub = true;
            }
            //문제 < b-ii >
            //이미 해당 topic을 다른 publisher가 등록했다면, 등록할 수 없게 처리함.
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
                if(tBox[*tBoxNum].clientId.subfd[i] == -1) {
                    tBox[*tBoxNum].clientId.subfd[i] = connfd;
                    n_sub[*tBoxNum]++;
                    isPub = false;
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
        err("read nothing about 'TopicBox.clientInfo.pubfd'");
        err("connection lost");
        close(connfd);
        reapPollfds(connfd);
    } else {
        readBuffer[n] = '\0';
        (*tBoxNum) = atoi(readBuffer);
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

    pollfds[0].fd = listenfd;
    pollfds[0].events = POLLIN;
    pollfds[0].revents = 0;
    for(i=1; i <= CLI_NUM; i++) {
        pollfds[i].fd = -1;
        pollfds[i].revents = 0;
    }

    int tBoxNum;
    bool everIn = false;
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

            //regiTopic이 성공한 경우
            if(regiTopic(connfd, &tBoxNum)) {
                for(int k=1; k<=CLI_NUM; k++) {
                    if(pollfds[k].fd == -1) {
                        pollfds[k].fd = connfd;
                        if(isPub) pollfds[k].events = POLLIN;
                        else pollfds[k].events = POLLOUT;
                        pollfds[k].revents = 0;
                        break;
                    }
                }
                //regiTopic이 성공하면 해당 connfd 자체를 client의 ID로 부여한다.
                sprintf(writeBuffer, "%d", connfd);
                writevn(connfd, writeBuffer, strlen(writeBuffer));
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
        for(i=1; i<=CLI_NUM; i++) {
            everIn = false;
            //first: receive a msg
            //printf("%d\n", maxi);
            switch(pollfds[i].revents) {
                case 0:
                    break; //no events

                case POLLIN:
                    recvMsg(pollfds[i].fd, &tBoxNum);
                    pollfds[i].revents = 0;
                    everIn = true;
                    break;

                case POLLOUT:
                    break;

                default:
                    err("invalid revents");
                    close(pollfds[i].fd);
                    reapPollfds(pollfds[i].fd);
                    break;
            }


            //문제 < d-i >
            //문제 < d-ii >
            //publisher로 부터 받은 topic message에 메세지가 담겨있다면,
            //해당 내용을 subscriber에게 전송한다.
            if(tBox[tBoxNum].hasMsg && tBox[tBoxNum].isActivePub && everIn) {
                for(j=0; j<SUB_NUM; j++) {
                    if(tBox[tBoxNum].clientId.subfd[j] != -1) {
                        printf("[[BROKER]]: subfd[%d]에게 메세지를 보냄.\n", tBox[tBoxNum].clientId.subfd[j]);
                        forwardMsg(tBox[tBoxNum].clientId.subfd[j], tBoxNum);
                    }
                }
            }


            if(--nready <= 0) break;
        }// end for(i)
    }
}
