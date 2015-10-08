#include "header.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s IPv4-address\n", argv[0]);
        return -1;
    }

    struct sockaddr_in connectSocket;
    
    //클라이언트용 소켓(connectSocket)을 set 하시오
    int connectFD = socket(AF_INET, SOCK_STREAM, 0);
    connectSocket.sin_family = AF_INET;
    connectSocket.sin_port = htons(PORT);
    connectSocket.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(connectFD, (struct sockaddr*) &connectSocket, sizeof(connectSocket)) == -1) {
        printf("Can not connect.\n");
        return -1;
    } else {
        char buffer[BUFFER_SIZE];
        //int n = readn(connectFD, buffer, BUFFER_SIZE);
        int n = readvn(connectFD, buffer, BUFFER_SIZE);
        

        buffer[n] = '\0';
        printf("%s\n", buffer);
        //fputs(buffer, stdout);
        //fflush(stdout);
    }
    
    close(connectFD);
    return 0;
}
