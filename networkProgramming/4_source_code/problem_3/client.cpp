#include "header.h" //필요한 헤더를 추가하시오.
#include <errno.h>
#define TIMEOUT 5
#define TEST(x) printf("%s", x)
void alarmHandler(int sig) {
    //클라이언트 프로그램을 종료하시오.
    return;
}

int main(int argc, char** argv) {
    signal(SIGALRM, alarmHandler);

    struct sigaction act;
    memset(&act, '\0', sizeof(act));
    act.sa_handler = &alarmHandler;
    sigaction(SIGALRM, &act, NULL);

    if (argc != 2) {
        printf("Usage: %s IPv4-address\n", argv[0]);
        return -1;
    }

    struct sockaddr_in serverSocket;
    memset(&serverSocket, 0, sizeof(serverSocket));
    serverSocket.sin_family = AF_INET;
    inet_aton(argv[1], (struct in_addr*) &serverSocket.sin_addr.s_addr);
    serverSocket.sin_port = htons(PORT);

    int clientSocketFD = socket(AF_INET, SOCK_DGRAM, 0);
    int readBytes;
    char sendBuffer[BUFFER_SIZE];
    char receiveBuffer[BUFFER_SIZE];
    char exitString[5] = "exit";
    while (true) {
        //사용자로부터 문자열을 입력받으시오.
        printf("Input: ");
        //scanf("%s", sendBuffer);
        fgets(sendBuffer, BUFFER_SIZE, stdin);
        fflush(stdin);

        //서버에 입력받은 문자열을 전송하시오.
        sendto(clientSocketFD, sendBuffer, strlen(sendBuffer), 0, (struct sockaddr*)&serverSocket, sizeof(serverSocket));

        //alarm 시그널을 이용해 5초 동안 응답이 없으면 프로그램을 종료하시오. 응답을 받고 alarm 시그널을 취소하시오.
        alarm(TIMEOUT);

        if((readBytes = recvfrom(clientSocketFD, receiveBuffer, BUFFER_SIZE, 0, NULL, NULL)) < 0 ) {
            if(errno == EINTR) {
                fprintf(stderr, "socket timeout\n");
                return -1; //shut down because of an interrupt.
            }
            else {
                printf("recvfrom error occured!!\n");
            }
        } else {
            //응답을 받고 alarm 시그널을 취소하시오.
            alarm(0);
            receiveBuffer[readBytes] = '\0'; //null terminate

            if(strncmp(receiveBuffer, exitString, strlen(receiveBuffer)-1) == 0) {
                printf("-------------------------------\n");
                printf("You let this program shut down.\n");
                printf("Bye Bye~\n");
                return 0;
            }

            //서버로부터 입력받은 문자열을 출력하시오
            printf("%s", receiveBuffer);
            //fputs(receiveBuffer, stdout);
        }
        //서버로부터 입력받은 문자열을 출력하시오.
    }
    return 0;
}
