#include "header.h"
//#include <errno.h>

#define LISTEN_QUEUE_SIZE 5

int main() {
    
    struct sockaddr_in listenSocket;
    
    //서버용 리슨 소켓(listenSocket)을 set 하시오
    listenSocket.sin_family = AF_INET; //TCP
    listenSocket.sin_addr.s_addr = htonl(INADDR_ANY); //Any incoming interface
    listenSocket.sin_port = htons(PORT); //PORT

    int listenFD = socket(AF_INET, SOCK_STREAM, 0);

    if( bind(listenFD, (struct sockaddr *)&listenSocket, sizeof(listenSocket)) == -1 ) {
        printf("Can not bind.\n");
        return -1;
    }

    if( listen(listenFD, LISTEN_QUEUE_SIZE) == -1 ) {
        printf("Listen fail.\n");
        return -1;
    }

    printf("Waiting for clients...\n");

    while(1) {
        struct sockaddr_in connectSocket, peerSocket;
        socklen_t connectSocketLength = sizeof(connectSocket);

        //클라이언트의 접속을 허가하여 소켓 ID(connectFD)를 set 하시오
        int connectFD = accept(listenFD, (struct sockaddr*)&connectSocket, &connectSocketLength);

        getpeername(connectFD, (struct sockaddr*)&peerSocket, &connectSocketLength);
        char peerName[sizeof(peerSocket.sin_addr) + 1] = {0};
        sprintf(peerName, "%s", inet_ntoa(peerSocket.sin_addr));

        printf("Client : %s\n", peerName);

        char buffer[BUFFER_SIZE] = {0};
        sprintf(buffer, "Hello, %s\n", peerName);
        //writen(connectFD, buffer, htonl(strlen(buffer)));
        writevn(connectFD, buffer, strlen(buffer));

        close(connectFD);
    }

    close(listenFD);
    return 0;
}
