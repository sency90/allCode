# include "header.h"
# include <stdlib.h>
# include <arpa/inet.h>

# include <pthread.h>

# define LISTEN_QUEUE_SIZE 5

struct echoThreadParameter {
	int connectFD;
	char* peerName;
};

void* echoThread(void* echoParameter);

int main() {
	struct sockaddr_in listenSocket;
	memset(&listenSocket, 0, sizeof(listenSocket));
	listenSocket.sin_family = AF_INET;
	listenSocket.sin_addr.s_addr = htonl(INADDR_ANY);
	listenSocket.sin_port = htons(PORT);

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

	pthread_t threadID;

	while (1) {
		struct sockaddr_in connectSocket, peerSocket;
		socklen_t connectSocketLength = sizeof(connectSocket);

		struct echoThreadParameter* echoParameter = malloc(sizeof(struct echoThreadParameter));
		echoParameter->connectFD = accept(listenFD, (struct sockaddr*)&connectSocket, &connectSocketLength);

		getpeername(echoParameter->connectFD, (struct sockaddr*)&peerSocket, &connectSocketLength);
		echoParameter->peerName = (char*) calloc((sizeof(peerSocket.sin_addr) + 1), sizeof(char));
		sprintf(echoParameter->peerName, inet_ntoa(peerSocket.sin_addr), "%s");

		pthread_create(&threadID, NULL, (void*) echoThread, (void*)  echoParameter);
	}
	close(listenFD);

	return 0;
}

void* echoThread(void* echoParameter) {
	struct echoThreadParameter* castedEchoParameter = (struct echoThreadParameter*) echoParameter;

	pthread_t threadID;
	threadID = pthread_self();
	pthread_detach(threadID);

	printf("Thread ID %u is ready to work.\n", (unsigned int)threadID);

	printf("Client %s is in.\n", castedEchoParameter->peerName);
	serverEcho(castedEchoParameter->connectFD, castedEchoParameter->peerName);
	printf("Client %s is out.\n",  castedEchoParameter->peerName);

	close(castedEchoParameter->connectFD);
	free(castedEchoParameter->peerName);
	free(castedEchoParameter);

	return NULL ;
}
