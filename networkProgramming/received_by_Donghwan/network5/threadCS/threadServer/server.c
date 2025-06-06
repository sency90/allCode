# include "header.h"
# include <string.h>
# include <stdlib.h>
# include <arpa/inet.h>

# include <pthread.h>

# define LISTEN_QUEUE_SIZE 5
# define POOL_SIZE 2
# define NAME_SIZE 16

typedef struct {
 pthread_t threadID;
 long threadCount;
} workerThread;
workerThread *workerThreadPointer;

int readIndex, writeIndex;
int clientFDs[POOL_SIZE];
char* clientNames[POOL_SIZE];

pthread_mutex_t clientFDMutex;
pthread_cond_t clientFDCondition;

void threadCreate(int index);
void* threadJob(void* indexPointer);

int main() {
 struct sockaddr_in listenSocket;
 memset(&listenSocket, 0, sizeof(listenSocket));
 listenSocket.sin_family = AF_INET;
 listenSocket.sin_addr.s_addr = htonl(INADDR_ANY);
 listenSocket.sin_port = htons(PORT);

 int listenFD = socket(AF_INET, SOCK_STREAM, 0);
 if (bind(listenFD, (struct sockaddr *) &listenSocket, sizeof(listenSocket)) == -1) {
  printf("Can not bind.\n");
  return -1;
 }

 if (listen(listenFD, LISTEN_QUEUE_SIZE) == -1) {
  printf("Listen fail.\n");
  return -1;
 }

 printf("Waiting for clients...\n");

 workerThreadPointer = calloc(POOL_SIZE, sizeof(workerThread));
 readIndex = writeIndex = 0;

 int i;
//POOL_SIZE = 2
 for (i = 0; i < POOL_SIZE; i++) {
  clientNames[i] = malloc(NAME_SIZE * sizeof(char));
  threadCreate(i);
 }

 while (1) {
  struct sockaddr_in connectSocket, peerSocket;
  socklen_t connectSocketLength = sizeof(connectSocket);

  int connectFD = accept(listenFD, (struct sockaddr*)&connectSocket, &connectSocketLength);
  pthread_mutex_lock(&clientFDMutex); // lock
  clientFDs[writeIndex] = connectFD;

  getpeername(connectFD, (struct sockaddr*)&peerSocket, &connectSocketLength);
  memset(clientNames[writeIndex], 0, NAME_SIZE * sizeof(char));
  sprintf(clientNames[writeIndex], "%s", inet_ntoa(peerSocket.sin_addr));

  if (++writeIndex == POOL_SIZE) {
   writeIndex = 0;
  }

  if (writeIndex == readIndex) {
   printf("Queue error.\n");
   exit(1);
  }

  pthread_cond_signal(&clientFDCondition); // condition
  pthread_mutex_unlock(&clientFDMutex); //unlock
 }
 close(listenFD);

 for(i = 0; i < POOL_SIZE; i++) {
  free(clientNames[i]);
 }

 return 0;
}

void threadCreate(int index) {
 int* indexPointer = malloc(sizeof(int));
 *indexPointer = index;

 pthread_create(&workerThreadPointer[index].threadID, NULL, &threadJob, (void*) indexPointer);
}

void * threadJob(void* indexPointer) {
 int connectFD;
 int index = *(int*) indexPointer;
 char* peerName;

 printf("thread %d starting.\n", index);

 while (1) {
  pthread_mutex_lock(&clientFDMutex);
  while (readIndex == writeIndex) {
   pthread_cond_wait(&clientFDCondition, &clientFDMutex);
  }

  connectFD = clientFDs[readIndex];
  peerName = clientNames[readIndex];

  if (++readIndex == POOL_SIZE) {
   readIndex = 0;
  }

  pthread_mutex_unlock(&clientFDMutex);

  workerThreadPointer[index].threadCount++;

  printf("Client %s is in.\n", peerName);
  serverEcho(connectFD, peerName);
  printf("Client %s is out.\n", peerName);

  free(indexPointer);
  close(connectFD);
 }
 return NULL;
}
