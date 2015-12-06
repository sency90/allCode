#include "commonHeader.h"
//문제 < c-ii >
//문제에서 요구한대로 topic.h라는 공통된 헤더파일을 pub와 sub가 포함하도록 함.
#include "topic.h"
#include <signal.h>

int globalConnfd;
char readBuffer[BUFFER_SIZE];
char writeBuffer[BUFFER_SIZE];

char prevTimeInfo[TIME_INDEX_SIZE];
int n;

struct clientInfoForSub {
    int subfd;
    int tBoxNum;
}thisSubInfo;

//문제 < c-ii >
//문제에서 요구한대로 pub와 sub가 서로 주고 받을 topic message에 대한 구조체 정보를 가지고 있다.
struct TopicMsg tMsg;

void sendRegiTopic(int connfd, char* tBoxNum);
void recvMsg(int connfd);

//문제 < c-v >
//reset을 위해서 호출되는 함수이다.
void handler(int signal) {
    if(!strcmp(prevTimeInfo, tMsg.timeInfo)) {
        alarm(3);
        //reset the msg box
        tMsg.msg[0] = '\0';
        //tMsg.timeInfo[0] = '\0';

        printf("[[ SUBSCRIBER[%d] - registered topic number: %d ]]\n", thisSubInfo.subfd, thisSubInfo.tBoxNum);
        printf("This sub has waited a msg for 3 seconds and haven't recevied any msgs.\n");
        printf("So this msg box has been flushed\n");
        printf("Received Msg: %s\n", tMsg.msg);
        printf("Time Stamp: %s\n\n", tMsg.timeInfo);
        readBuffer[0] = '\0';
    }
}

//문제 < b-iii >
//subscriber가 topic을 등록할 때 쓰는 함수이다.
void sendRegiTopic(int connfd, char* tBoxNum) {
    sprintf(writeBuffer, "%d", SUB);
    writevn(connfd, writeBuffer, strlen(writeBuffer));
    writevn(connfd, tBoxNum, strlen(tBoxNum));
}

void recvMsg(int connfd) {
    //문제 < c-v >
    //3초동안 메세지를 받지 못했을 때 reset하기 위해서 alarm을 3초로 설정하였다.
    alarm(3);
    
    strcpy(prevTimeInfo, tMsg.timeInfo);
    globalConnfd = connfd; //global variable connfd에 local var connfd를 저장해둔다.
    if( (n = readvn(connfd, readBuffer, BUFFER_SIZE)) == 0 ) {
        printf("Disconnected with the broker\n");
        exit(1);
    }
    readBuffer[n]='\0';
    strcpy(tMsg.msg, readBuffer);

    if( (n = readvn(connfd, readBuffer, BUFFER_SIZE)) == 0 ) {
        printf("Disconnected from the broker\n");
        exit(1);
    }
    readBuffer[n]='\0';
    strcpy(tMsg.timeInfo, readBuffer);

    printf("[[ SUBSCRIBER[%d] - registered topic number: %d ]]\n", thisSubInfo.subfd, thisSubInfo.tBoxNum);
    printf("Received Msg: %s\n", tMsg.msg);
    printf("Time Stamp: %s\n\n", tMsg.timeInfo);
}

int main(int argc, char** argv) {
    if(argc != 2) return -1;

    int n;

    char tBoxNum[TBOXNUM_INDEX_SIZE];
    strcpy(tBoxNum, argv[1]);
    thisSubInfo.tBoxNum = atoi(tBoxNum);

    struct sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = inet_addr(LOCAL_IP);
    clientAddr.sin_port = htons(PORT);

    printf("Waiting for creating a client socket...\n");
    //int* connfd = (int*)malloc(sizeof(int));
    int connfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("The socket was created successfully!!\n");

    printf("Waiting for connection to the chatting server...\n");
    int x;
    if((x=connect(connfd, (struct sockaddr*)&clientAddr, sizeof(clientAddr))) < 0 ) {
        printf("Error: Cannot connect with the server\n");
        exit(-1);
    } else {
        printf("Connection complete!\n");

        //문제 < b-iii >
        //topic box number를 broker에 등록한다.
        sendRegiTopic(connfd, tBoxNum);

        if( (n = readvn(connfd, readBuffer, BUFFER_SIZE)) == 0 ) {
            err("no allocated subfd");
            exit(1);
        }
        readBuffer[n] = '\0';
        thisSubInfo.subfd = atoi(readBuffer);
        if(thisSubInfo.subfd == -1) {
            err("sendRegiTopic was failed.");
            exit(1); //exit this subscriber
        }
        printf("Issued topic box number is %d\n\n", thisSubInfo.subfd);

        //문제 < c-v >
        //정해진 시간동안 토픽 메세지가 오지 않는 경우 reset하기 위해서
        //SIGALRM 시그널을 설정해준다. (결론적으로 이 문제는 alarm을 써서 해결하였다.)
        signal(SIGALRM, handler);

        while(1) {
            recvMsg(connfd);
        }
    }

    return 0;
}
