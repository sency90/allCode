# include "stdio.h"
# include <stdlib.h>

# include <pthread.h>
# include <semaphore.h>

# include <unistd.h>

# define QUEUE_SIZE 10
# define ITERATION_NUMBER 20

# define PRODUCER_NUMBER 2
# define CONSUMER_NUMBER 2

struct {
 int queue[QUEUE_SIZE];
 int writeIndex;
 int readIndex;
 int num;
} sharedQueue;


sem_t canWrite;
sem_t canRead;

void queueInitialize() {
 sharedQueue.readIndex = 0;
 sharedQueue.writeIndex = 0;
 sharedQueue.num = 0;

 sem_init(&canWrite, 0, 1);
 sem_init(&canRead, 0, 0);
}

void* producer(void* param) {
 int i;

 for (i = 0; i < ITERATION_NUMBER; i++) {
  do {
   sem_wait(&canWrite);
  } while (sharedQueue.num == QUEUE_SIZE);

  sharedQueue.queue[sharedQueue.writeIndex] = i;
  sharedQueue.writeIndex = (sharedQueue.writeIndex + 1) % QUEUE_SIZE;
  sharedQueue.num++;
  printf("producer %u wrote %d.\n", (unsigned int) pthread_self(), i);

  if ((sharedQueue.num < QUEUE_SIZE)) {
   sem_post(&canWrite);
  }

  sem_post(&canRead);
 }
 return NULL;
}

void* consumer(void* param) {
 int i;

 while (1) {
  do {
   sem_wait(&canRead);
  } while (sharedQueue.num == 0);

  i = sharedQueue.queue[sharedQueue.readIndex];
  sharedQueue.readIndex = (sharedQueue.readIndex + 1) % QUEUE_SIZE;
  sharedQueue.num--;
  printf("consumer %u red %d.\n", (unsigned int) pthread_self(), i);

  if ((sharedQueue.num > 0)) {
   sem_post(&canRead);
  }

  sem_post(&canWrite);
 }
 return NULL;
}

int main() {
 pthread_t producerThreads[PRODUCER_NUMBER];
 pthread_t consumerThreads[CONSUMER_NUMBER];

 queueInitialize();

 int i;
 for (i = 0; i < PRODUCER_NUMBER; i++) {
  pthread_create(&producerThreads[i], NULL, producer, NULL);
 }
 for (i = 0; i < CONSUMER_NUMBER; i++) {
  pthread_create(&consumerThreads[i], NULL, consumer, NULL);
 }

 for (i = 0; i < PRODUCER_NUMBER; i++) {
  pthread_join(producerThreads[i], NULL);
 }
 for (i = 0; i < CONSUMER_NUMBER; i++) {
  pthread_join(consumerThreads[i], NULL);
 }

 printf("Job done\n");
 return 0;
}
