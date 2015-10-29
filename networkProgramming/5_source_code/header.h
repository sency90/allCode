# include <stdio.h>
# include <string.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <errno.h>
# include <cstdlib>
# include <ctime>
# include <sys/wait.h>
# include <cstdio>
# include <ostream>
# define PORT 10001
# define BUFFER_SIZE 100
ssize_t readvn(int socketFD, char* buffer, size_t maxLength);
ssize_t writevn(int socketFD, char* buffer, size_t length);
