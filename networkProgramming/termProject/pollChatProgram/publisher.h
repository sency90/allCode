# define PORT 10001
# define BUFFER_SIZE 100
# define LISTENQ 6
# define ID_SIZE 100

#include <semaphore.h> //for synchronization
#include <pthread.h> //for pthread
#include <string.h> //for readvn(), writevn()
#include <stdio.h> //for printf(), scanf()
#include <arpa/inet.h> //for inet_addr()
#include <stdlib.h> //for exit()

ssize_t readvn(int socketFD, char* buffer, size_t length);
ssize_t readn(int socketFD, char* buffer, size_t length);
ssize_t writevn(int socketFD, char* buffer, size_t length);
ssize_t writen(int socketFD, char* buffer, size_t length);