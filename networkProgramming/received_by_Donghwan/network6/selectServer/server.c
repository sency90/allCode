# include "header.h"

# define LISTEN_QUEUE_SIZE 5
# define FD_SET_SIZE 256

int main(int argc, char **argv) {
	struct sockaddr_in listenSocket;
	memset(&listenSocket, 0, sizeof(listenSocket));
	listenSocket.sin_family = AF_INET;
	listenSocket.sin_addr.s_addr = htonl(INADDR_ANY);
	listenSocket.sin_port = htons(PORT);

	int listenFD = socket(AF_INET, SOCK_STREAM, 0);
	if (bind(listenFD, (struct sockaddr *) &listenSocket, sizeof(listenSocket))
			== -1) {
		printf("Can not bind.\n");
		return -1;
	}

	if (listen(listenFD, LISTEN_QUEUE_SIZE) == -1) {
		printf("Listen fail.\n");
		return -1;
	}

	printf("Waiting for clients...\n");

	while(1) {
		
	}
}
