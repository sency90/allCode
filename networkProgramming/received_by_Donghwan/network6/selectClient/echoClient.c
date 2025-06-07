# include "header.h"
# include <errno.h>

ssize_t readn(int socketFD, char* buffer, size_t length) {
	ssize_t redBytes = 0;
	size_t leftBytes = length;
	char* pointer = buffer;

	while (leftBytes > 0) {
		redBytes = read(socketFD, pointer, leftBytes);

		if (redBytes < 0) {
			if (errno == EINTR) {
				redBytes = 0;
			} else {
				return -1;
			}
		} else if (redBytes == 0) {
			break;
		}

		leftBytes -= redBytes;
		pointer += redBytes;
	}

	return length - leftBytes;
}

ssize_t readvn(int socketFD, char* buffer, size_t maxLength) {
	ssize_t redBytes = 0;
	size_t valueLength;

	redBytes = readn(socketFD, (char*) &valueLength, sizeof(size_t));
	if (redBytes < 0) {
		return -1;
	} else if (redBytes == 0) {
		return 0;
	}

	valueLength = ntohl(valueLength);
	if (valueLength > maxLength) {
		return -1;
	}

	redBytes = readn(socketFD, buffer, valueLength);
	if (redBytes < 0) {
		return -1;
	} else if (redBytes == 0) {
		return 0;
	}

	return redBytes;
}

ssize_t writen(int socketFD, const char* buffer, size_t length) {
	ssize_t writtenBytes = 0;
	size_t leftBytes = length;
	const char* pointer = buffer;

	while (leftBytes > 0) {
		writtenBytes = write(socketFD, pointer, leftBytes);
		if (writtenBytes <= 0) {
			if (errno == EINTR) {
				writtenBytes = 0;
			} else {
				return -1;
			}
		}

		leftBytes -= writtenBytes;
		pointer += writtenBytes;
	}

	return length;
}

ssize_t writevn(int socketFD, const char* buffer, size_t length) {
	ssize_t writtenBytes = 0;
	size_t valueLength = htonl(length);

	writtenBytes = writen(socketFD, (char*) &valueLength, sizeof(size_t));
	if (writtenBytes < 0) {
		return -1;
	}

	writtenBytes = writen(socketFD, buffer, length);
	if (writtenBytes < 0) {
		return -1;
	}

	return writtenBytes;
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}


