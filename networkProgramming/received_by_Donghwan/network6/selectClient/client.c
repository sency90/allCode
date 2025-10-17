# include "header.h"

void clientEcho(FILE *filePointer, int connectFD) {
	
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Usage: %s IPv4-address\n", argv[0]);
		return -1;
	}

	struct sockaddr_in connectSocket;
	memset(&connectSocket, 0, sizeof(connectSocket));
	connectSocket.sin_family = AF_INET;
	inet_aton(argv[1], (struct in_addr*) &connectSocket.sin_addr.s_addr);
	connectSocket.sin_port = htons(PORT);

	int connectFD = socket(AF_INET, SOCK_STREAM, 0);

	if (connect(connectFD, (struct sockaddr*) &connectSocket, sizeof(connectSocket)) == -1) {
		printf("Can not connect.\n");
		return -1;
	} else {
		clientEcho(stdin, connectFD);
	}
	close(connectFD);

	return 0;
}
