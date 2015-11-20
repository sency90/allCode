#include "header.h"
#include <sys/select.h>

void err_quit(const char* str) {
    perror(str);
    exit(1);
}

int main(int argc, char **argv) {
    int i, maxi, maxfd, listenfd, connfd, sockfd;
    int nready, client[FD_SETSIZE];
    ssize_t n_message;
    ssize_t n_id;
    int n_conn = 0; //connection 개수
    fd_set rset, allset;

    //FD_SETSIZE 개수만큼 id저장 가능, 각각의 ID size는 ID_SIZE 크기를 넘지 못함.
    char user_id[FD_SETSIZE][ID_SIZE];
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

    for(i=0; i<FD_SETSIZE; i++) {
        client[i] = -1; //-1 indicates available entry
    }

    FD_ZERO(&allset); //set all bits of 'allset' as 0
    FD_SET(listenfd, &allset); //register listenfd to 'allset'

    while(1) {
        rset = allset; //structure assignment
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);

        /* 1 */
        //accepting clients which requested to connect to this server
        if( FD_ISSET(listenfd, &rset)) { //new client connection
            if(n_conn >= 4) {
                printf("Too many clients. Only 4 clients can connect!");
                --nready;
                continue;
            } else {
                clilen = sizeof(cliaddr);
                connfd = accept(listenfd, (sockaddr*)&cliaddr, &clilen);
                n_conn++;

                for(i=0; i<FD_SETSIZE; i++) {
                    if(client[i] < 0) {
                        client[i] = connfd; //save descriptor
                        break;
                    }
                }

                if(i == FD_SETSIZE) {
                    err_quit("too many clients\n");
                }
                FD_SET(connfd, &allset); //add new descriptor to set

                if(connfd > maxfd) maxfd = connfd; //for select
                if(i > maxi) maxi = i; //max index in client[] array
                if(--nready <= 0) continue; //no more readable descriptors
            }
        }

        /* 2 */
        //handling messages which were sent by some clients
        for(i=0; i<=maxi; i++) { //check all clients for data
            if((sockfd = client[i]) < 0) {
                continue;
            }
            if(FD_ISSET(sockfd, &rset)) {

                //read a client ID
                if((n_id = readvn(sockfd, temp_id, ID_SIZE)) == 0) {
                    printf("%s님께서 종료하셨습니다.\n", user_id[i]);
                    temp_id[n_id]='\0';
                    //user_id[i][n_id]='\0';

                    //사용하지 않을거지만 다음 read를 위해 남은 message도 처리해줘야 한다.
                    n_message = readvn(sockfd, line, BUFFER_SIZE);
                    line[n_message]='\0';

                    close(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                    n_conn--;

                    sprintf(line, "%s님께서 종료하셨습니다.\n", user_id[i]);

                    for(int j=0; j<=maxi; j++) {
                        if(client[j] >= 0) {
                            writevn(client[j], user_id[i], strlen(user_id[i]));
                            writevn(client[j], line, strlen(line));
                        }
                    }
                }
                else {
                    temp_id[n_id]='\0';
                    strcpy(user_id[i], temp_id);
                    user_id[i][n_id]='\0';

                    //read a message
                    n_message = readvn(sockfd, line, BUFFER_SIZE);
                    line[n_message]='\0';

                    //broadcasting the client ID and message to all clients
                    for(int j=0; j<=maxi; j++) {
                        if(client[j] >= 0) { //broadcasting the received message to all clients
                            writevn(client[j], user_id[i], n_id);
                            writevn(client[j], line, n_message);
                        }
                    }
                }

                if(--nready <= 0) {
                    break; //no more readable descriptors
                }
            } //end if(FD_ISSET())
        } //end for(i)
    }
}
