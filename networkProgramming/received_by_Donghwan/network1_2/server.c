# include <stdio.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <arpa/inet.h>

# include <errno.h>

# define PORT 9000
# define LISTEN_QUEUE_SIZE 5
# define BUFFER_SIZE 100


ssize_t writen(int socketFD, const char* buffer, size_t length);
ssize_t writevn(int socketFD, const char* buffer, size_t length);

int main() {
	struct sockaddr_in listenSocket;
	memset(&listenSocket, 0, sizeof(listenSocket));
	listenSocket.sin_addr.s_addr = htonl(INADDR_ANY );
	listenSocket.sin_family = AF_INET;
	listenSocket.sin_port = htons(PORT);

	int listenFD = socket(AF_INET, SOCK_STREAM, 0);
	if (bind(listenFD, (struct sockaddr *) &listenSocket, sizeof(listenSocket)) == -1) {
		printf("Can not bind\n");
		return -1;
	}

	if (listen(listenFD, LISTEN_QUEUE_SIZE) == -1) {
		printf("listen fail\n");
		return -1;
	}

	printf("Waiting for clients...\n");

	while (1) {
		struct sockaddr_in connectSocket, peerSocket;
		int connectSocketLength = sizeof(connectSocket);
		int connectFD = accept(listenFD, (struct sockaddr*)&connectSocket, &connectSocketLength);
		getpeername(connectFD, (struct sockaddr*)&peerSocket, &connectSocketLength);

		printf("Client : %s\n", inet_ntoa(peerSocket.sin_addr));

		char sendingBuffer[BUFFER_SIZE];

		sprintf(sendingBuffer, "Hello, %s", inet_ntoa(peerSocket.sin_addr));

		write(connectFD, sendingBuffer, strlen(sendingBuffer));
		writen(connectFD, sendingBuffer, strlen(sendingBuffer));
		writevn(connectFD, sendingBuffer, strlen(sendingBuffer));

		close(connectFD);
	}
	close(listenFD);

	return 0;
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

	writtenBytes = write(socketFD, (char*)&valueLength, sizeof(size_t));
	if (writtenBytes < 0) {
		return -1;
	}

	writtenBytes = write(socketFD, buffer, length);
	if (writtenBytes < 0) {
		return -1;
	}

	return length;
}
