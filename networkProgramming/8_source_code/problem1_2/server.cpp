//server.cpp
# include "header.h"
# include "rw_vn.h"
# include <stdlib.h>
# include <pthread.h>
# define LISTEN_QUEUE_SIZE 10
# define THREAD_NUMBER 4

//뮤텍스를 초기화 하시오.
int counter;
pthread_mutex_t acceptMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t listenMutex = PTHREAD_MUTEX_INITIALIZER;

void mutexDestroy() {
    //뮤텍스를 제거하시오.
    pthread_mutex_destroy(&acceptMutex);
    pthread_mutex_destroy(&listenMutex);
}
void *workerTask(void *argument) {

    pthread_mutex_lock(&listenMutex);
    long long *listenFD = (long long*) argument;
    pthread_mutex_unlock(&listenMutex);
    //pthread_detach()
    struct sockaddr_in connectSocket;
    socklen_t connectSocketLength = sizeof(connectSocket);
    int connectFD;
    int integer1, integer2, sum;
    int readBytes, writtenBytes;
    char sendBuffer[BUFFER_SIZE];
    char receiveBuffer[BUFFER_SIZE];
    int n;

    //while (true) {
    //뮤텍스를 이용해 accept를 보호하시오
    pthread_mutex_lock(&acceptMutex);
    connectFD = accept(*listenFD, (struct sockaddr*)&connectSocket, &connectSocketLength);
    pthread_mutex_unlock(&acceptMutex);

    while(true) {
        //클라이언트와 통신하시오.

        n = readvn(connectFD, receiveBuffer, BUFFER_SIZE);
        receiveBuffer[n] = '\0';
        integer1 = atoi(receiveBuffer);

        n = readvn(connectFD, receiveBuffer, BUFFER_SIZE);
        receiveBuffer[n] = '\0';
        integer2 = atoi(receiveBuffer);

        sum = integer1 + integer2;
        sprintf(sendBuffer, "%d", sum);
        writevn(connectFD, sendBuffer, BUFFER_SIZE);

        //close(connectFD);
    }
    close(connectFD);
    return NULL;
}

int main() {
    struct sockaddr_in listenSocket;
    memset(&listenSocket, 0, sizeof(listenSocket));
    listenSocket.sin_family = AF_INET;
    listenSocket.sin_addr.s_addr = htonl(INADDR_ANY );
    listenSocket.sin_port = htons(PORT);

    long long *listenFD = (long long*)malloc(sizeof(long long));
    *listenFD = socket(AF_INET, SOCK_STREAM, 0);
    if (bind(*listenFD, (struct sockaddr *) &listenSocket, sizeof(listenSocket)) == -1) {
        printf("Can not bind.\n");
        fflush(stdout);
        close(*listenFD);
        free(listenFD);
        mutexDestroy();
        return -1;
    }
    if (listen(*listenFD, LISTEN_QUEUE_SIZE) == -1) { printf("Listen fail.\n");
        fflush(stdout);
        close(*listenFD);
        mutexDestroy();
        return -1;
    }

    printf("Waiting for clients...\n");
    fflush(stdout);
    pthread_t workers[THREAD_NUMBER];
    int threadNumber;
    for (threadNumber = 0; threadNumber < THREAD_NUMBER; threadNumber++) {
        int threadCreateResult;
        threadCreateResult = pthread_create(&workers[threadNumber], NULL, workerTask, listenFD);
        if (threadCreateResult != 0) {
            printf("Thread create error\n");
            fflush(stdout);
            break;
        }
    }
    for (int i = 0; i < threadNumber; i++) {
        pthread_join(workers[i], NULL);
    }
    close(*listenFD);
    free(listenFD);
    mutexDestroy();
    return 0;
}
