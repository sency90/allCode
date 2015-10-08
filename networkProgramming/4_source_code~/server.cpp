#include "header.h" //필요한 헤더를 추가하시오.
#include <errno.h>
#define LISTEN_QUEUE_SIZE 5
void childHandler(int signal) {
    //모든 child process가 종료될 때까지 기다리시오.
    while(waitpid(-1, 0, WNOHANG) > 0);
    return;
}
void echo(int connfd) {
    ssize_t n = 0;
    char buffer[BUFFER_SIZE];

    while(1) {
        n = read(connfd, buffer, BUFFER_SIZE);

        if( n < 0 ) {
            if(errno == EINTR) n = 0;
            //printf("buffer: %s\n", buffer);
            fflush(stdout);
        }
        else if( n == 0 ) return;
        else {
            buffer[n] = '\0';
            fputs(buffer, stdout);
            fflush(stdout);

            //if(std::strcmp(buffer, "q") || std::strcmp(buffer, "Q")) break; // q라는 문자가 전송되면 echo프로그램을 종료

            write(connfd, buffer, strlen(buffer));
        }
    }
    return;
}
int main() {
    //childHandler 함수가 SIGCHLD 시그널을 처리할 수 있도록 하시오.
    signal(SIGCHLD, childHandler);

    struct sockaddr_in listenSocket;
    memset(&listenSocket, 0, sizeof(listenSocket));
    listenSocket.sin_family = AF_INET;
    listenSocket.sin_addr.s_addr = htonl(INADDR_ANY );
    listenSocket.sin_port = htons(PORT);

    int listenFD = socket(AF_INET, SOCK_STREAM, 0);
    if (bind(listenFD, (struct sockaddr *) &listenSocket, sizeof(listenSocket)) == -1) {
        printf("Can not bind.\n");
        return -1;
    }
    if (listen(listenFD, LISTEN_QUEUE_SIZE) == -1) { printf("Listen fail.\n");
        return -1;
    }
    printf("Waiting for clients...\n");
    while (1) {
        struct sockaddr_in connectSocket, peerSocket;
        socklen_t connectSocketLength = sizeof(connectSocket);
        int connectFD = accept(listenFD, (struct sockaddr*)&connectSocket, &connectSocketLength);

        getpeername(connectFD, (struct sockaddr*)&peerSocket, &connectSocketLength);
        char peerName[sizeof(peerSocket.sin_addr) + 1] = {0};
        sprintf(peerName, "%s", inet_ntoa(peerSocket.sin_addr));
        printf("Client : %s\n", peerName);

        //클라이언트가 접속할 때마다 fork를 통해 child process를 생성해 echo를 수행하시오.
        if( fork() == 0) {
            close(listenFD);
            echo(connectFD);
            close(connectFD);
            exit(0);
        }
        close(connectFD);
    }
    close(listenFD);
    return 0;
}
