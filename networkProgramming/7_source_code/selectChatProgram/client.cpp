#include "header.h"
#include <semaphore.h> //for synchronization

using namespace std;

char id[ID_SIZE];

sem_t s;

struct shared_st {
    sem_t s;
    sem_t synch;
};

struct shared_st shared;

void P(sem_t *sem) {
    sem_wait(sem);
}

void V(sem_t *sem) {
    sem_post(sem);
}

//This function must be performed atomically
ssize_t writevnChat(int sockfd, char* buffer, size_t length, char* userID) {
    writevn(sockfd, userID, strlen(userID));
    return writevn(sockfd, buffer, strlen(buffer));
}

//This function must be performed atomically
ssize_t readvnChat(int sockfd, char* buffer, size_t length, char* userID) {
    int n;

    if( (n = readvn(sockfd, userID, ID_SIZE)) == 0 ) {
        userID[n]='\0';
        printf("Connection was down. Server was dead.\n");
        exit(1);
    }
    userID[n]='\0';
    n = readvn(sockfd, buffer, BUFFER_SIZE);
    buffer[n]='\0';

    return n;
}

static void scanMsg(int connfd, char* wBuffer) {
    //printf("[%s]Input: ", id);
    scanf("%s", wBuffer);
    if(!strcmp(wBuffer, "exit")) {
        //terminating this tid_sendMsg thread, and then this client will be closed.
        exit(0);
    }

    writevnChat(connfd, wBuffer, strlen(wBuffer), id);
}

static void printMsg(int connfd, char* rBuffer, char* userID) {
    //Print messages if the ones are in the readBuffer
    if( 0 < readvnChat(connfd, rBuffer, BUFFER_SIZE, userID) ) {
        printf("[%s]: %s\n", userID, rBuffer);
    }
}



void* broadcastEnteredID(void *arg) {
    int connfd = *(int*)arg;

    pthread_detach(pthread_self());
    //free(arg);

    char tempBuffer[BUFFER_SIZE];
    sprintf(tempBuffer, "%s", "<<NEWBIE_ENTERED_THIS_ROOM>>\n");
    writevnChat(connfd, tempBuffer, strlen(tempBuffer), id);

    exit(0);
}


void* sendMsg(void *arg) {
    P(&s);
    int connfd = *(int*)arg;

    //for running independently of other threads to separate this thread with others.
    //and for being reaped when it terminates
    pthread_detach(pthread_self());
    free(arg);
    V(&shared.s);
    V(&shared.synch);

    char wBuffer[BUFFER_SIZE];
    while(1) {
        scanMsg(connfd, wBuffer);
    }

    return NULL;
}

void* recvMsg(void *arg) {
    V(&s);
    int connfd = *(int*)arg;

    //for running independently of other threads to separate this thread with others.
    //and for being reaped when it terminates
    pthread_detach(pthread_self());
    P(&shared.s);
    P(&shared.synch);

    char rBuffer[BUFFER_SIZE];
    char userID[ID_SIZE];
    while(1) {
        printMsg(connfd, rBuffer, userID);
    }

    return NULL;
}


int main(int argc, char** argv) {

    sem_init(&shared.s, 0, 0); //initialize the semaphore
    sem_init(&shared.synch, 0, 0);

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);//inet_aton(argv[1]);
    serverAddr.sin_port = htons(PORT);

    printf("Waiting for creating a client socket...\n");
    int* connfd = (int*)malloc(sizeof(int));
    *connfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("The socket was created successfully!!\n\n");

    printf("Please enter your username\n");
    do {
        printf("Username: ");
        scanf("%s", id);
    } while(id == NULL);

    printf("Waiting for connection to the chatting server...\n");
    int x;
    if((x=connect(*connfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr))) < 0 ) {
        printf("Error: Cannot connect with the server\n");
        exit(-1);
    } else {

        //broadcasting to inform that this client has entered.
        char tempBuffer[BUFFER_SIZE];
        sprintf(tempBuffer, "%s님이 입장하셨습니다.\n", id);
        writevnChat(*connfd, tempBuffer, strlen(tempBuffer), id);

        //broadcastEnteredID(connfd);

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
