#include "header.h"
#include <sys/poll.h>
#define NUMPOLL 50
#define LIMIT_FD 5

void err_quit(const char* str) {
    perror(str);
    exit(1);
}

int main(int argc, char **argv) {
    char server_id[ID_SIZE] = "SERVER";

    int i, n, maxi, maxfd, listenfd, connfd;
    int nready = 0;
    ssize_t n_message;
    ssize_t n_id;
    int n_conn = 0; //connection 개수
    //fd_set rset, allset;
    struct pollfd pollfds[NUMPOLL];

    //NUMPOLL 개수만큼 id저장 가능, 각각의 ID size는 ID_SIZE 크기를 넘지 못함.
    char user_id[NUMPOLL][ID_SIZE];
    char line[BUFFER_SIZE];
    char temp_id[ID_SIZE];

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
    for(i=1; i<NUMPOLL; i++) {
        pollfds[i].fd = -1;
    }

    //FD_ZERO(&allset); //set all bits of 'allset' as 0
    //FD_SET(listenfd, &allset); //register listenfd to 'allset'

    while(1) {
        if((nready = poll(pollfds, NUMPOLL, -1)) < 0) {
            perror("poll failed");
            exit(3);
        }

        /* 1 */
        //accepting clients which requested to connect to this server
        if(pollfds[0].revents == POLLIN) { //request connection from new client
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (sockaddr*)&cliaddr, &clilen);
            n_conn++;

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
