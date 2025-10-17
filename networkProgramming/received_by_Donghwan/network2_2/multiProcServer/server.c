# include "header.h"
# include <stdlib.h>
# include <arpa/inet.h>

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# define LISTEN_QUEUE_SIZE 5

void sigchld_handler(int sig);

int main() {
	struct sockaddr_in listenSocket;
	memset(&listenSocket, 0, sizeof(listenSocket));
	listenSocket.sin_family = AF_INET;
	listenSocket.sin_addr.s_addr = htonl(INADDR_ANY);
	listenSocket.sin_port = htons(PORT);

	signal(SIGCHLD, sigchld_handler);

	int listenFD = socket(AF_INET, SOCK_STREAM, 0);
	if (bind(listenFD, (struct sockaddr *) &listenSocket, sizeof(listenSocket)) == -1) {
		printf("Can not bind.\n");
		return -1;
	}

	if (listen(listenFD, LISTEN_QUEUE_SIZE) == -1) {
		printf("Listen fail.\n");
		return -1;
	}

	printf("Waiting for clients...\n");

	while (1) {
		struct sockaddr_in connectSocket, peerSocket;
		socklen_t connectSocketLength = sizeof(connectSocket);
		int connectFD = accept(listenFD, (struct sockaddr*)&connectSocket, &connectSocketLength);

		getpeername(connectFD, (struct sockaddr*)&peerSocket, &connectSocketLength);
		char peerName[sizeof(peerSocket.sin_addr) + 1] = {0};
		sprintf(peerName, inet_ntoa(peerSocket.sin_addr), "%s");

		if (fork() == 0) {
			close(listenFD);

			char peerAddress[sizeof(peerSocket.sin_addr) + 1];
			sprintf(peerAddress, inet_ntoa(peerSocket.sin_addr), "%s");

			printf("Client %s is in.\n", peerAddress);
			serverEcho(connectFD, peerAddress);
			printf("Client %s is out.\n", peerAddress);

			close(connectFD);
			exit(0);
		}

		close(connectFD);
	}
	close(listenFD);

	return 0;
}

void sigchld_handler(int sig) {
	while (waitpid(-1, 0, WNOHANG) > 0) {}
	return;
}
