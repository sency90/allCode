#include "header.h"
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s IPv4-address\n", argv[0]);
        return -1;
    }
    struct sockaddr_in connectSocket;
    memset(&connectSocket, 0, sizeof(connectSocket));
    connectSocket.sin_family = AF_INET;
    inet_aton(argv[1], (struct in_addr*) &connectSocket.sin_addr.s_addr);
    connectSocket.sin_port = htons(PORT);

    int connectFD = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(connectFD, (struct sockaddr*) &connectSocket, sizeof(connectSocket)) == -1) {
        printf("Can not connect.\n");
        return -1;
    } else {
        int readBytes, writtenBytes;
        char sendBuffer[BUFFER_SIZE];
        char receiveBuffer[BUFFER_SIZE];

        while (true) {
            //서버에 문자열을 보낸 뒤 서버가 보낸 echo를 받아 출력하시오.
            printf("Input: ");

            fgets(sendBuffer, BUFFER_SIZE, stdin);
            fflush(stdin);

            if(strlen(sendBuffer) <= 0) {
                printf("Nothing was typed!!\n");
                printf("Please input again.\n");
                continue;
            }

            if(strncmp(sendBuffer, "exit", strlen(sendBuffer)-1) == 0) {
                printf("--------------------------------\n");
                printf("You let this program shut down.\n");
                printf("Bye Bye~\n");
                return 0;
            }

            writtenBytes = write(connectFD, sendBuffer, strlen(sendBuffer));
            if(writtenBytes < 0) {
                fprintf(stderr, "write failed!\n");
                return -1;
            } else if(writtenBytes == 0) {
                continue;
            }

            readBytes = read(connectFD, receiveBuffer, BUFFER_SIZE);
            if( readBytes < 0 ) {
                fprintf(stderr, "read failed!\n");
                continue;
            } else if(readBytes == 0) {
                continue;
            } else {
                receiveBuffer[readBytes] = '\0';
                printf("Echo: ");
                printf("%s\n", receiveBuffer);
            }
        }
    }
    close(connectFD);
    return 0;
}
