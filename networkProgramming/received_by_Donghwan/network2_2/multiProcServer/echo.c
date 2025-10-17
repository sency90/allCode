# include "header.h"
# include <errno.h>

ssize_t readn(int socketFD, char* buffer, size_t length) {
	ssize_t redBytes = 0;
	size_t leftBytes = length;
	char* pointer = buffer;

	//

	return length - leftBytes;
}

ssize_t readvn(int socketFD, char* buffer, size_t maxLength) {
	ssize_t redBytes = 0;
	size_t valueLength;

	//

	return redBytes;
}

ssize_t writen(int socketFD, const char* buffer, size_t length) {
	ssize_t writtenBytes = 0;
	size_t leftBytes = length;
	const char* pointer = buffer;

	//

	return length;
}

ssize_t writevn(int socketFD, const char* buffer, size_t length) {
	ssize_t writtenBytes = 0;
	size_t valueLength = htonl(length);

	//

	return length;
}

void clientEcho(int connectFD) {
	char buffer[BUFFER_SIZE] = { 0 };

	//
}

void serverEcho(int connectFD, char* peerAddress) {
	char buffer[BUFFER_SIZE] = { 0 };
	int n;

	//
}
