#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <cstdlib>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define NITERS 5
#define EMPTY -1

void *producer(void *arg);
void *consumer(void *arg);

struct shared_st{
    int buf; //shared var
    sem_t full; //semaphore
    sem_t empty;
    sem_t s;
};

struct shared_st shared;

void P(sem_t *sem) {
    sem_wait(sem);
}

void V(sem_t *sem) {
    sem_post(sem);
}

int main() {

    pthread_t tid_producer;
    pthread_t tid_consumer;

    sem_init(&shared.empty, 0, 1);
    sem_init(&shared.full, 0, 0);
    sem_init(&shared.s, 0, 0);

    pthread_create(&tid_producer, NULL, producer, NULL);
    pthread_create(&tid_consumer, NULL, consumer, NULL);
    pthread_join(tid_producer, NULL);
    pthread_join(tid_consumer, NULL);

    exit(0);

    return 0;
}

void *producer(void *arg) {
    int i, item;
    shared.buf = EMPTY;

    for(i=0; i<NITERS; i++) {
        //produce item

        item = i;

        //write item to buf
        P(&shared.empty);
        //produce item
        while(1) {
            if(shared.buf == EMPTY) {
                shared.buf = item;
                printf("[producer]: produced %d\n", item);
                break;
            } else {
                printf("[producer]: consumed %d which was produced by the consumer\n", shared.buf);
                shared.buf = EMPTY;
            }
        }
        V(&shared.full);

    }

    return NULL;
}

void *consumer(void *arg) {
    int i, item;

    for(i=0; i<NITERS; i++) {
        //read item from buf
        P(&shared.full);
        if(shared.buf != EMPTY) {
            item = shared.buf; //2번문제 해결
            shared.buf = EMPTY; //비어있음을 표시
            //consume item
            printf("[consumer]: consumed %d\n", item);
        }
        V(&shared.s);

        P(&shared.s);
        if(shared.buf == EMPTY) {
            shared.buf = item+1;
            printf("[consumer]: produeced %d with increased one\n", item+1);
        }
        V(&shared.empty);
    }

    return NULL;
}
