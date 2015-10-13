#include "header.h"
 
int main(int argc, char *argv[]) {
	
	int sockfd; 
	struct sockaddr_in serverAddr; 
	//struct hostent *server;

	char buffer[BUFFER_SIZE];
	int n;

	if(argc != 2) {
		printf("Usage: %s IPv4-address\n", argv[0]);
		return -1;
	}
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0); //tcp socket creation	

	serverAddr.sin_family = AF_INET; //tcp
	serverAddr.sin_port = htons(PORT);	//port no
	serverAddr.sin_addr.s_addr = inet_addr(argv[1]); //host name (ip address)

	if(connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) return -1;
	
	n = read(sockfd, buffer, BUFFER_SIZE);
	printf("%d bytes read\n", n);

	buffer[n] = '\0';
	fputs(buffer, stdout);
	fflush(stdout);
	//bcopy((char *)server->h_addr, (char *)&serverAddr.sin_addr.s_addr, server->h_length); 
	//send(sockfd, buffer, strlen(buffer), 0);
	//sprintf("Client: Hello\n");
	
	//서버와의 접속을 끊으시오
	close(sockfd); 
	return 0; 
}
