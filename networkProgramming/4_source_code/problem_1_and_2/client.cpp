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
        char buffer[BUFFER_SIZE];

        printf("Input: ");
        scanf("%s", buffer);

        while (true) {
            //서버에 문자열을 보낸 뒤 서버가 보낸 echo를 받아 출력하시오.
            //memset(buffer, 0, BUFFER_SIZE);
            //fgets(buffer, BUFFER_SIZE, stdin);
            //fflush(stdin);

            if(strlen(buffer) <= 0) {
                printf("[nothing was typed!!]\n");
                //fflush(stdout);
                break;
            }

            if(buffer[0] == 'q' && buffer[1]=='\0') {
                printf("%s\n", buffer);
                printf("shut down !!\n");
                break;
            }

            write(connectFD, buffer, strlen(buffer));

            int n = read(connectFD, buffer, BUFFER_SIZE);
            if( n < 0 ) {
                printf("read failed.\n");
                //fflush(stdout);
                break;
            } else if(n == 0) {
                break;
            } else {
                buffer[n] = '\0';
                printf("Echo: ");
                printf("%s\n", buffer);
                //fputs(buffer, stdout);
                //fflush(stdout);
            }
        }
    }
    close(connectFD);
    return 0;
}
