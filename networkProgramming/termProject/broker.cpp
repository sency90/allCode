#include "commonHeader.h"
#include "topic.h"
#include <sys/poll.h>
//#define NUMPOLL 50
//#define LIMIT_FD 5

TopicBox tBox[TBOX_NUM + 1];
int n_pub_all = 0;
int n_sub[TBOX_NUM + 1] = {0};

void err_quit(const char* str) {
    perror(str);
    exit(1);
}


bool regiTopic(int connfd, char* kindOfChar, int* tBoxNum) {
    int n;
    bool hasErr = false;
    char topicBoxNum[TBOXNUM_INDEX_SIZE];

    n = readvn(connfd, kindOfChar, TBOXNUM_INDEX_SIZE);
    kindOfChar[n] = '\0';

    n = readvn(connfd, topicBoxNum, sizeof(topicBoxNum));
    topicBoxNum[n] = '\0';

    *tBoxNum = atoi(topicBoxNum);

    //if tBoxNum is valid
    if(*tBoxNum == 1 || *tBoxNum == 2 || *tBoxNum == 3) {
        //변경되기전 tBox[*topicBox]를 저장한다. (에러가 발생하면 다시 원상태로 되돌린다.)
        TopicBox origTBox = tBox[*tBoxNum];

        //요청받은 tBoxNum에 해당하는 tBox를 active 시킨다.
        tBox[*tBoxNum].isActive = true;

        //Publisher가 topic 등록을 요청했다면,
        if(strcmp(kindOfChar, PUB)) {
            if(tBox[*tBoxNum].clientId.pubfd == INIT) {
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
        else if(strcmp(kindOfChar, SUB)) {
            int i; //for for-loop index
            for(i=0; i<SUB_NUM; i++) {
                if(tBox[*tBoxNum].clientId.subfd[i] == INIT) {
                    tBox[*tBoxNum].clientId.subfd[i] = connfd;
                    n_sub[*tBoxNum]++;
                    break;
                }
            }
            //바로 위에서 for 반복문을 모두 돌았는데도 subfd가 INIT인 애들이 없다면,
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

int main(int argc, char **argv) {
    //char server_id[ID_SIZE] = "SERVER";

    int i, n, maxi, maxfd, listenfd, connfd;
    int nready = 0;
    ssize_t n_message;
    ssize_t n_id;
    //fd_set rset, allset;
    struct pollfd pollfds[CLI_NUM];

    //NUMPOLL 개수만큼 id저장 가능, 각각의 ID size는 ID_SIZE 크기를 넘지 못함.
    //char user_id[][ID_SIZE];
    char line[BUFFER_SIZE];
    //char temp_id[ID_SIZE];

    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    bind(listenfd, (sockaddr*)&servaddr, sizeof(servaddr));
    listen(listenfd, LISTENQ);

    maxfd = listenfd; //initialize
    maxi = -1; //index into client[] array

    pollfds[0].fd = listenfd;
    pollfds[0].events = POLLIN;
    pollfds[0].revents = 0;
    for(i=1; i < (CLI_NUM); i++) {
        pollfds[i].fd = -1;
    }

    //FD_ZERO(&allset); //set all bits of 'allset' as 0
    //FD_SET(listenfd, &allset); //register listenfd to 'allset'

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
            //n_conn++;

            char kindOfChar[TBOXNUM_INDEX_SIZE];
            int tBoxNum;

            //regiTopic이 성공한 경우
            if(regiTopic(connfd, kindOfChar, &tBoxNum)) {
                for(int k=0; k<CLI_NUM; i++) {
                    if(pollfds[k].fd == -1) {
                        pollfds[k].fd = connfd;
                        pollfds[k].events = POLLIN;
                        pollfds[k].revents = 0;
                        break;
                    }
                }
                //regiTopic이 성공하면 해당 connfd 자체를 client의 ID로 부여한다.
                char temp_fd[FD_INDEX_SIZE];
                sprintf(temp_fd, "%d", connfd);
                writevn(connfd, temp_fd, sizeof(temp_fd));
            }
            //regiTopic이 실패한 경우, 요청한 해당 클라이언트와 아예 연결을 끊어버린다.
            else {
                char err_fd[FD_INDEX_SIZE];
                sprintf(err_fd, "%d", -1);
                writevn(connfd, err_fd, sizeof(err_fd));
                close(connfd);
            }

///////////////////////////////////////////////////////////////////////////////////////////////////////////








            if(n_conn == LIMIT_FD) {
                writevn(connfd, server_id, strlen(server_id));
                sprintf(line, "Too many clients. Your connection request was rejected\n");
                writevn(connfd, line, strlen(line));

                close(connfd);
                n_conn--;
                continue;
            }

            for(i=1; i<NUMPOLL; i++) {
                if(pollfds[i].fd == -1) {
                    pollfds[i].fd = connfd;
                    pollfds[i].events = POLLIN;
                    pollfds[i].revents = 0;
                    break;
                }
            }


            if(i == NUMPOLL) {
                perror("too many clients.\n The limited number of client is 4.\n");
                exit(1);
            }

            if(connfd > maxfd) maxfd = connfd; //for select
            if(i > maxi) maxi = i; //max index in client[] array
            if(--nready <= 0) continue; //no more readable descriptors
        }

        /* 2 */
        //handling messages which were sent by some clients
        for(i=1; i<=maxi; i++) { //check all clients for data
            switch(pollfds[i].revents) {
                case 0: break; //no events
                case POLLIN:
                        //read a client ID
                        if((n_id = readvn(pollfds[i].fd, temp_id, ID_SIZE)) == 0) {
                            printf("%s님께서 종료하셨습니다.\n", user_id[i]);
                            temp_id[n_id]='\0';
                            //user_id[i][n_id]='\0';

                            //사용하지 않을거지만 다음 read를 위해 남은 message도 처리해줘야 한다.
                            n_message = readvn(pollfds[i].fd, line, BUFFER_SIZE);
                            line[n_message]='\0';

                            close(pollfds[i].fd);
                            pollfds[i].fd = -1;
                            pollfds[i].revents = 0;
                            n_conn--;

                            sprintf(line, "%s님께서 종료하셨습니다.\n", user_id[i]);

                            for(int j=1; j<=maxi; j++) {
                                if(pollfds[j].fd >= 0) {
                                    writevn(pollfds[j].fd, user_id[i], strlen(user_id[i]));
                                    writevn(pollfds[j].fd, line, strlen(line));
                                }
                            }
                        }
                        else {
                            temp_id[n_id]='\0';
                            strcpy(user_id[i], temp_id);
                            user_id[i][n_id]='\0';

                            //read a message
                            n_message = readvn(pollfds[i].fd, line, BUFFER_SIZE);
                            line[n_message]='\0';

                            //broadcasting the client ID and message to all clients
                            for(int j=1; j<=maxi; j++) {
                                if(pollfds[j].fd >= 0) { //broadcasting the received message to all clients
                                    writevn(pollfds[j].fd, user_id[i], n_id);
                                    writevn(pollfds[j].fd, line, n_message);
                                }
                            }
                        }

                        if(--nready <= 0) {
                            break; //no more readable descriptors
                        }
                        break;

                default:
                        perror("error event");
                        close(pollfds[i].fd);
                        pollfds[i].fd = -1;
                        pollfds[i].revents = 0;
                        break;

            } //end switch
        } //end for(i)
    }
}