# include "header.h"
# include <signal.h>
# include <errno.h>

# define TIMEOUT 5

void alarmHandler(int sig) {}

void echoClientSignal(int socketFD, const struct sockaddr* dataSocket, socklen_t dataSocketLength) {
	char buffer[BUFFER_SIZE];

	struct sigaction alarmAction = {
		.sa_handler = alarmHandler,
		.sa_flags = 0,
	};

	sigaction(SIGALRM, &alarmAction, NULL);

	while (1) {
		memset(buffer, 0, BUFFER_SIZE);
		printf("Input: ");
		fgets(buffer, BUFFER_SIZE, stdin);
		fflush(stdin);

		if(strlen(buffer) <= 0) {
			printf("\n");
			fflush(stdout);
			return;
		}

		sendto(socketFD, buffer, strlen(buffer), 0, dataSocket, dataSocketLength);

		alarm(TIMEOUT);
		int n = recvfrom(socketFD, buffer, BUFFER_SIZE, 0, NULL, NULL);
		alarm(0);

		if(n <= 0) {
			if(errno == EINTR) {
				printf("socket timeout.\n");
				fflush(stdout);
				return;
			} else {
				continue;
			}
		}

		buffer[n] = '\0';
		printf("Echo: ");
		fputs(buffer, stdout);
		fflush(stdout);
	}
}

void echoClientSelect(int socketFD, const struct sockaddr* dataSocket, socklen_t dataSocketLength) {
	char buffer[BUFFER_SIZE];

	fd_set socketFDS;
	struct timeval timeout;

	FD_ZERO(&socketFDS);
	FD_SET(socketFD, &socketFDS);

	timeout.tv_sec = TIMEOUT;
	timeout.tv_usec = 0;

	while (1) {
		memset(buffer, 0, BUFFER_SIZE);
		printf("Input: ");
		fgets(buffer, BUFFER_SIZE, stdin);
		fflush(stdin);

		if(strlen(buffer) <= 0) {
			printf("\n");
			fflush(stdout);
			return;
		}

		sendto(socketFD, buffer, strlen(buffer), 0, dataSocket, dataSocketLength);

		if(select(socketFD+1, &socketFDS, NULL, NULL, &timeout)){
			int n = recvfrom(socketFD, buffer, BUFFER_SIZE, 0, NULL, NULL);
			if (n <= 0) continue;

			buffer[n] = '\0';
			printf("Echo: ");
			fputs(buffer, stdout);
			fflush(stdout);
		} else {
			printf("socket timeout.\n");
			fflush(stdout);
			return;
		}
	}
}
