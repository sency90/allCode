//server.cpp
#include "header.h"
#include "rw_vn.h"
#include <pthread.h>
#include <errno.h>

#define LISTEN_QUEUE_SIZE 10
#define THREAD_NUMBER 4

struct queue{
    int queue[THREAD_NUMBER];
    int writeIndex;
    int readIndex;
    int count;
} sharedQueue;

//뮤텍스와 컨디션을 초기화 하시오.
pthread_mutex_t countMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t prodCond = PTHREAD_COND_INITIALIZER;
pthread_cond_t consCond = PTHREAD_COND_INITIALIZER;

void initializeQueue() {
    sharedQueue.readIndex = 0;
    sharedQueue.writeIndex = 0;
    sharedQueue.count = 0;
}

void mutexDestroy() {
    //뮤텍스와 컨디션을 제거하시오.
    pthread_mutex_destroy(&countMutex);
    pthread_cond_destroy(&consCond);
    pthread_cond_destroy(&prodCond);
}

void *workerTask(void *argument) {
    int connectFD;
    int integer1, integer2, sum;
    int readBytes, writtenBytes;
    char sendBuffer[BUFFER_SIZE];
    char receiveBuffer[BUFFER_SIZE];
    int n;

    struct sockaddr_in connectSocket;
    socklen_t connectSocketLength = sizeof(connectSocket);

    //프로듀서가 제공한 connect FD를 이용해 클라이언트와 통신하시오.
    pthread_mutex_lock(&countMutex);
    if(sharedQueue.count == 0) {
        pthread_cond_wait(&prodCond, &countMutex);
    }
    connectFD = sharedQueue.queue[sharedQueue.readIndex++];
    if(sharedQueue.readIndex == THREAD_NUMBER) sharedQueue.readIndex = 0;
    sharedQueue.count--;
    pthread_cond_signal(&consCond);
    pthread_mutex_unlock(&countMutex);

    while (true) {
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

    int *listenFD = (int *)malloc(sizeof(int));
    *listenFD = socket(AF_INET, SOCK_STREAM, 0);
    if (bind(*listenFD, (struct sockaddr *) &listenSocket, sizeof(listenSocket)) == -1) {

        printf("Can not bind.\n");
        fflush(stdout);
        close(*listenFD);
        free(listenFD);
        mutexDestroy();
        return -1;
    }

    if (listen(*listenFD, LISTEN_QUEUE_SIZE) == -1) {

        printf("Listen fail.\n");
        fflush(stdout);
        close(*listenFD);
        free(listenFD);
        mutexDestroy();
        return -1;
    }

    printf("Waiting for clients...\n");
    fflush(stdout);

    struct sockaddr_in connectSocket;
    socklen_t connectSocketLength = sizeof(connectSocket);
    int connectFD;
    initializeQueue();
    pthread_t workers[THREAD_NUMBER] = {0};
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
    while (true) {
        connectFD = accept(*listenFD, (struct sockaddr*)&connectSocket, &connectSocketLength);
        //connect FD를 공유 큐에 추가하여 컨슈머가 사용할 수 있도록 하시오.

        pthread_mutex_lock(&countMutex);
        if(sharedQueue.count >= THREAD_NUMBER) {
            pthread_cond_wait(&consCond, &countMutex);
        }
        sharedQueue.queue[sharedQueue.writeIndex++] = connectFD;
        if(sharedQueue.writeIndex == THREAD_NUMBER) {
            sharedQueue.writeIndex = 0;
        }
        sharedQueue.count++;
        pthread_cond_signal(&prodCond);
        pthread_mutex_unlock(&countMutex);

    }
    for (int i = 0; i < threadNumber; i++) {
        pthread_join(workers[i], NULL);
    }
    close(*listenFD);
    free(listenFD);
    mutexDestroy();
    return 0;
}
