# include "header.h"
int main() {

    struct sockaddr_in serverSocket, clientSocket;
    memset(&serverSocket, 0, sizeof(serverSocket));
    serverSocket.sin_family = AF_INET;
    serverSocket.sin_addr.s_addr = htonl(INADDR_ANY);
    serverSocket.sin_port = htons(PORT);

    int serverSocketFD = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Waiting for clients...\n");
    if (bind(serverSocketFD, (struct sockaddr*) &serverSocket, sizeof(serverSocket)) == -1) {
        printf("Can not bind.\n");
        return -1;
    }
    int readBytes;
    char sendBuffer[BUFFER_SIZE];
    while (1) {
        //클라이언트가 보낸 문자열을 다시 클라이언트에게 보내시오.
    }
    return 0;
}
