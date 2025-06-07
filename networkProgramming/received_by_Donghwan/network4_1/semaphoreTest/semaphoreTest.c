# include <stdio.h>
# include <stdlib.h>

# include <pthread.h>
# include <semaphore.h>

# define ASSIGNMENT 1000000
# define THREAD_NUMBER 4

void Sem_init(sem_t *sem, int pshared, unsigned int value) {
	if (sem_init(sem, pshared, value) < 0) {
		printf("Initialize fail\n");
		exit(1);
	}
}

void P(sem_t *sem) {
	if (sem_wait(sem)) {
		printf("P fail\n");
		exit(1);
	}
}

void V(sem_t *sem) {
	if (sem_post(sem)) {
		printf("V fail\n");
		exit(1);
	}
}

void* count(void *arg);
volatile unsigned int sum;
sem_t sem;

int main() {
	pthread_t threadIDs[THREAD_NUMBER];
	Sem_init(&sem, 0, 1);

	int n;
	for (n = 0; n < THREAD_NUMBER; n++) {
		pthread_create(&(threadIDs[n]), NULL, count, NULL);
		printf("%u ready for work.\n", (unsigned int)threadIDs[n]);
	}

	for (n = 0; n < THREAD_NUMBER; n++) {
		pthread_join(threadIDs[n], NULL);
	}

	printf("sum = %d\n", sum);
	return 0;
}

void* count(void *arg) {
	int i;
	for (i = 0; i < ASSIGNMENT; i++) {
		P(&sem);
		sum++;
		V(&sem);
	}
	return NULL;
}

