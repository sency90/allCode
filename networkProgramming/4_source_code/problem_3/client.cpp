# include "header.h" //필요한 헤더를 추가하시오.
# define TIMEOUT 5
void alarmHandler(int sig) {
    //클라이언트 프로그램을 종료하시오.
    return;
}
int main(int argc, char** argv) {
    signal(SIGALRM, alarmHandler);

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
    while (true) {
        //사용자로부터 문자열을 입력받으시오.
        printf("Input: ");
        scanf("%s", sendBuffer);

        //sendto(clientSocketFD, sendBuffer, strlen(sendBuffer), 0, serverSocket, sizeof(serverSocket));
        //서버에 입력받은 문자열을 전송하시오.
        sendto(clientSocketFD, sendBuffer, strlen(sendBuffer), 0, serverSocket, sizeof(serverSocket));

        //alarm 시그널을 이용해 5초 동안 응답이 없으면 프로그램을 종료하시오. 응답을 받고 alarm 시그널을 취소하시오.
        //서버로부터 입력받은 문자열을 출력하시오.
    }
    return 0;
}
