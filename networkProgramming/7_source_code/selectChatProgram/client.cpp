#include "header.h"

#define ID_SIZE 100

using namespace std;

char id[ID_SIZE];

//This function must be performed atomically
ssize_t writevnChat(int sockfd, char* buffer, size_t length, char* userID) {
    writevn(sockfd, userID, sizeof(userID));
    return writevn(sockfd, buffer, sizeof(buffer));
}

//This function must be performed atomically
ssize_t readvnChat(int sockfd, char* buffer, size_t length, char* userID) {
    readvn(sockfd, userID, ID_SIZE);
    return readvn(sockfd, buffer, BUFFER_SIZE);
}

static void inputMsg() {
    printf("[%s]Input: ", id);
    scnaf("%s", wBuffer);
    if(wBuffer == "exit") {
        //terminating this tid_sendMsg thread, and then this client will be closed.
        exit(0);
    }

    writevnChat(connfd, wBuffer, sizeof(wBuffer), id);
}

static void outputMsg() {
    //Print messages if the ones are in the readBuffer
    if( 0 < readvnChat(connfd, rBuffer, BUFFER_SIZE, userID) ) {
        printf("[%s]: %s\n", userID, rBuffer);
    }
}






void sendMsg(void *arg) {
    int connfd = *(int*)arg;

    //for running independently of other threads to separate this thread with others.
    //and for being reaped when it terminates
    pthread_detach(pthread_self());
    free(arg);

    char wBuffer[BUFFER_SIZE];
    while(1) {
        inputMsg();
    }
}

void recvMsg(void *arg) {
    int connfd = *(int*)arg;

    //for running independently of other threads to separate this thread with others.
    //and for being reaped when it terminates
    pthread_detach(pthread_self());
    free(arg);

    char rBuffer[BUFFER_SIZE];
    char userID[ID_SIZE];
    while(1) {        
        outputMsg();
    }
}


int main(int argc, char** argv) {

    struct sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = inet_addr(argv[1]);//inet_aton(argv[1]);
    clientAddr.sin_port = htons(PORT);

    pirntf("Waiting for creating a client socket...\n");
    int connfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("The socket was created successfully!!\n\n");

    printf("Please enter your username\n");
    printf("Username: ");
    scanf("%s", id);

    printf("Waiting for connection to the chatting server...\n");
    if(connect(connfd, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) < 0 ) {
        printf("Error: Cannot connect with the server\n");
        exit(-1);
    } else {
        printf("Connection complete!!\n");

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
