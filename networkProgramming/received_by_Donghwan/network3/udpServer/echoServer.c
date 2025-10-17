# include "header.h"

void echoServer(int socketFD, const struct sockaddr* dataSocket, socklen_t dataSocketLength) {
	char buffer[BUFFER_SIZE];
	socklen_t length;

	while (1) {
		length = dataSocketLength;
		int n = recvfrom(socketFD, buffer, BUFFER_SIZE, 0, (struct sockaddr*) dataSocket, &length);
		if (n < 0) n = 0;
		buffer[n] = '\0';

		printf("%s: ", inet_ntoa(((struct sockaddr_in*) dataSocket)->sin_addr));
		fflush(stdout);
		fputs(buffer, stdout);
		fflush(stdout);

		sendto(socketFD, buffer, n, 0, dataSocket, length);
	}
}
