# include "header.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Usage: %s IPv4-address\n", argv[0]);
		return -1;
	}

	struct sockaddr_in serverSocket;
	memset(&serverSocket, 0, sizeof(serverSocket));
	serverSocket.sin_family = AF_INET;
	inet_aton(argv[1], (struct in_addr*) &serverSocket.sin_addr.s_addr);
	serverSocket.sin_port = htons(PORT);

	int clientSocketFD = socket(AF_INET, SOCK_DGRAM, 0);

	echoClientSignal(clientSocketFD, (struct sockaddr*) &serverSocket, sizeof(serverSocket));

	return 0;
}
