#include "header.h"
#include <sys/select.h>

void err_quit(const char* str) {
    perror(str);
    exit(1);
}

int main(int argc, char **argv) {
    int i, maxi, maxfd, listenfd, connfd, sockfd;
    int nready, client[FD_SETSIZE];
    ssize_t n;
    fd_set rset, allset;
    char line[BUFFER_SIZE];

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

    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);

    while(1) {
        rset = allset; //structure assignment
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);
        if( FD_ISSET(listenfd, &rset)) { //new client connection
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (sockaddr*)&cliaddr, &clilen);

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

            if(connfd > maxfd) {
                maxfd = connfd; //for select
            }

            if(i > maxi) {
                maxi = i; //max index in client[] array
            }

            if(--nready <= 0) {
                continue; //no more readable descriptors
            }
        }

        for(i=0; i<=maxi; i++) { //check all clients for data
            if((sockfd = client[i]) < 0) {
                continue;
            }
            if(FD_ISSET(sockfd, &rset)) {
                if((n = readvn(sockfd, line, BUFFER_SIZE)) == 0) {
                    //connection closed by client
                    close(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                }
                else {
                    writen(sockfd, line, n);
                }

                if(--nready <= 0) {
                    break; //no more readable descriptors
                }
            }
        }
    }
}
