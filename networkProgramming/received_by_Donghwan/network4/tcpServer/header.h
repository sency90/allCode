# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# include <netinet/in.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>

# define PORT 8144
# define BUFFER_SIZE 1000

ssize_t readvn(int socketFD, char* buffer, size_t maxLength);
ssize_t writevn(int socketFD, const char* buffer, size_t length);

void serverEcho(int connectFD, const char* peerName);
