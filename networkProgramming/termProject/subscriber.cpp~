#include "commonHeader.h"
#include "topic.h"

struct clientInfoForSub {
    int subfd;
    int tBoxNum;
};

void sendRegiTopic(int connfd, char* tBoxNum) {
    char temp_sub[2];
    strcpy(temp_sub, SUB);

    writevn(connfd, temp_sub, strlen(temp_sub));
    writevn(connfd, tBoxNum, strlen(tBoxNum));
}

int main(int argc, char** argv) {
    if(argc != 2) return -1;

    int n;

    char tBoxNum[TBOXNUM_INDEX_SIZE];
    strcpy(tBoxNum, argv[1]);

    struct clientInfoForSub thisSubInfo;

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
    if((x=connect(connfd, (struct sockaddr*)&clientAddr, sizeof(clientAddr))) < 0 ) {
        printf("Error: Cannot connect with the server\n");
        exit(-1);
    } else {
        sendRegiTopic(connfd, tBoxNum);
        //clientId.tBoxNum = atoi(tBoxNum);
        char thisSubFd[FD_INDEX_SIZE];
        n = readvn(connfd, thisSubFd, sizeof(thisSubFd));
        thisSubFd[n] = '\0';
        if(strcmp(thisSubFd, "-1")) {
            err("sendRegiTopic was failed.");
            return -1; //exit this publisher
        }
        thisSubInfo.tBoxNum = atoi(tBoxNum);
        thisSubInfo.subfd = atoi(thisSubFd);
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
