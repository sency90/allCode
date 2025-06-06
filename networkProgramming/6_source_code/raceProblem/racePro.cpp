#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <cstdlib>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define N 5

void *thread(void *vargp);
/*
void P(sem_t *sem) {
    sem_wait(sem);
}

void V(sem_t *sem) {
    sem_post(sem);
}
*/

int main() {
    pthread_t tid[N];
    int i;

    for(i=0; i<N; i++) {
        pthread_create(&tid[i], NULL, thread, (void*)i);
    }
    for(i=0; i<N; i++) {
        pthread_join(tid[i], NULL);
    }
    exit(0);
}

//thread routine
void *thread(void *vargp) {
    int myid = (intptr_t)vargp;
    printf("Hello from thread %d\n", myid);
    return NULL;
}
