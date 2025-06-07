# include <stdio.h>
# include <netinet/in.h>
# include <sys/socket.h>

# include <errno.h>

# define PORT 9000
# define BUFFER_SIZE 100

ssize_t readn(int socketFD, char* buffer, size_t length);
ssize_t readln(int socketFD, char* buffer, size_t maxLength);
ssize_t readvn(int socketFD, char* buffer, size_t maxLength);

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Usage: %s IPv4-address\n", argv[0]);
		return -1;
	}

	struct sockaddr_in connectSocket;
	memset(&connectSocket, 0, sizeof(connectSocket));
	inet_aton(argv[1], &connectSocket.sin_addr.s_addr);
	connectSocket.sin_family = AF_INET;
	connectSocket.sin_port = htons(PORT);

	int connectFD = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(connectFD, (struct sockaddr*) &connectSocket,
			sizeof(connectSocket)) == -1) {
		printf("Can not connect.\n");
		return -1;
	} else {
		char recievingBuffer[BUFFER_SIZE];

		int n = read(connectFD, recievingBuffer, BUFFER_SIZE);
		printf("%d bytes read\n", n);
		recievingBuffer[n] = '\0';
		printf("%s\n", recievingBuffer);

		int n = readn(connectFD, recievingBuffer, BUFFER_SIZE);
		printf("%d bytes read\n", n);
		recievingBuffer[n] = '\0';
		printf("%s\n", recievingBuffer);

		int n = readln(connectFD, recievingBuffer, BUFFER_SIZE);
		printf("%d bytes read\n", n);
		recievingBuffer[n] = '\0';
		printf("%s\n", recievingBuffer);

		int n = readnn(connectFD, recievingBuffer, BUFFER_SIZE);
		printf("%d bytes read\n", n);
		recievingBuffer[n] = '\0';
		printf("%s\n", recievingBuffer);
	}
	close(connectFD);

	return 0;
}

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

ssize_t readln(int socketFD, char* buffer, size_t maxLength) {
	ssize_t redBytes;
	size_t length;
	char c;
	char* pointer = buffer;

	for (length = 1; length < maxLength; length++) {
		loop: redBytes = read(socketFD, &c, 1);

		if (redBytes == 1) {
			*pointer = c;
			pointer++;

			if (c == '\n') {
				break;
			}
		} else if (redBytes == 0) {
			if (length == 1) {
				return 0;
			} else {
				break;
			}
		} else {
			if (errno == EINTR) {
				goto loop;
			} else {
				return -1;
			}
		}
	}

	*pointer = '\0';
	return length;
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
