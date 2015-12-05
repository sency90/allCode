#include "commonHeader.h"
#include "topic.h"

char writeBuffer[BUFFER_SIZE];
char readBuffer[BUFFER_SIZE];
static int _si = 0;

struct clientInfoForPub {
    int pubfd;
    int tBoxNum;
}thisPubInfo;

void sendRegiTopic(int connfd, char* tBoxNum) {
    //char temp_pub[2];
    //strcpy(temp_pub, PUB);

    sprintf(writeBuffer, "%d", PUB);
    writevn(connfd, writeBuffer, strlen(writeBuffer));
    writevn(connfd, tBoxNum, strlen(tBoxNum));
}

void createMsg(int connfd) {

    sprintf(writeBuffer, "%d", thisPubInfo.tBoxNum);
    writevn(connfd, writeBuffer, strlen(writeBuffer));

    struct TopicMsg tMsg;
    sprintf(tMsg.msg, "publisher[%d]가 생산한 %d번째 msg", thisPubInfo.pubfd, ++_si);
    printf("%s\n", tMsg.msg);
    strcpy(writeBuffer, tMsg.msg);
    writevn(connfd, writeBuffer, strlen(writeBuffer));

    time_t timeStamp;
    time( &timeStamp );
    sprintf(tMsg.timeInfo, "%s", ctime(&timeStamp));
    strcpy(writeBuffer, tMsg.timeInfo);
    writevn(connfd, writeBuffer, strlen(writeBuffer));

    sleep(2);
}

int main(int argc, char** argv) {
    if(argc != 2) return -1;

    int n;

    char tBoxNum[TBOXNUM_INDEX_SIZE];
    strcpy(tBoxNum, argv[1]);
    thisPubInfo.tBoxNum = atoi(tBoxNum);

    //struct clientInfoForPub thisPubInfo;

    struct sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = inet_addr(LOCAL_IP);//inet_aton(argv[1]);
    clientAddr.sin_port = htons(PORT);

    printf("Waiting for creating a client socket...\n");
    //int* connfd = (int*)malloc(sizeof(int));
    int connfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("The socket was created successfully!!\n");

    printf("Waiting for connection to the chatting server...\n");
    int x;
    if( (x = connect(connfd, (struct sockaddr*)&clientAddr, sizeof(clientAddr))) < 0 ) {
        printf("Error: Cannot connect with the server\n");
        exit(-1);
    }
    else {
        printf("Connection complete!\n");
        //topic box number를 broker에 등록한다.
        sendRegiTopic(connfd, tBoxNum);

        //char thisPubFd[FD_INDEX_SIZE];
        //n = readvn(connfd, thisPubFd, sizeof(thisPubFd));
        //thisPubFd[n] = '\0';
        if( (n = readvn(connfd, readBuffer, BUFFER_SIZE)) == 0 ) {
            err("no allocated pubfd");
            exit(1);
        }
        readBuffer[n] = '\0';
        //thisPubInfo.tBoxNum = atoi(tBoxNum);
        //thisPubInfo.pubfd = atoi(thisPubFd);
        thisPubInfo.pubfd = atoi(readBuffer);
        if(thisPubInfo.pubfd == -1) {
            err("sendRegiTopic was failed.");
            exit(1);
        }
        printf("test - REGISTER COMPLETE!\n");

        //create msgs
        while(1) {
            //printf("test - createMsg\n");
            createMsg(connfd);
        }

        printf("Disconnected to the broker.\n");
    }

    return 0;
}
