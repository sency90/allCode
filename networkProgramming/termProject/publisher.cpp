#include "commonHeader.h"
#include "topic.h"

struct clientInfoForPub {
    int pubfd;
    int tBoxNum;
};

void sendRegiTopic(int connfd, char* tBoxNum) {
    char temp_pub[2];
    strcpy(temp_pub, PUB);

    writevn(connfd, temp_pub, strlen(temp_pub));
    writevn(connfd, tBoxNum, strlen(tBoxNum));
}

int main(int argc, char** argv) {
    if(argc != 2) return -1;

    int n;

    char tBoxNum[TBOXNUM_INDEX_SIZE];
    strcpy(tBoxNum, argv[1]);

    struct clientInfoForPub thisPubInfo;

    struct sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = inet_addr(LOCAL_IP);//inet_aton(argv[1]);
    clientAddr.sin_port = htons(PORT);

    printf("Waiting for creating a client socket...\n");
    //int* connfd = (int*)malloc(sizeof(int));
    int connfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("The socket was created successfully!!\n\n");

    printf("Waiting for connection to the chatting server...\n");
    int x;
    if( (x = connect(connfd, (struct sockaddr*)&clientAddr, sizeof(clientAddr))) < 0 ) {
        printf("Error: Cannot connect with the server\n");
        exit(-1);
    }
    else {
        //topic box number를 broker에 등록한다.
        sendRegiTopic(connfd, tBoxNum);

        char thisPubFd[FD_INDEX_SIZE];
        n = readvn(connfd, thisPubFd, sizeof(thisPubFd));
        thisPubFd[n] = '\0';
        if(strcmp(thisPubFd, "-1")) {
            err("sendRegiTopic was failed.");
            return -1; //exit this publisher
        }
        thisPubInfo.tBoxNum = atoi(tBoxNum);
        thisPubInfo.pubfd = atoi(thisPubFd);
////////////////////////////////////////////////////////////////////////////////////////////////////

        //broadcasting to inform that this client has entered.
        char tempBuffer[BUFFER_SIZE];
        sprintf(tempBuffer, "%s님이 입장하셨습니다.\n", id);
        writevnChat(*connfd, tempBuffer, strlen(tempBuffer), id);

        //creating thread IDs for sending and receiving messages.
        pthread_t tid_sendMsg;
        pthread_t tid_recvMsg;

        //creating threads with the above IDs.
        pthread_create(&tid_sendMsg, NULL, sendMsg, connfd);
        pthread_create(&tid_recvMsg, NULL, recvMsg, connfd);

        //joining threads with the main thread if they were terminated.
        pthread_join(tid_sendMsg, NULL);
        pthread_join(tid_recvMsg, NULL);

        printf("Disconnected to the server.\n");
    }

    return 0;
}