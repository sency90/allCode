#include"../network1.h"
#include<arpa/inet.h>

#define LISTEN_QUEUE_SIZE 5

int main(){
	struct sockaddr_in listenSocket;
	memset(&listenSocket, 0, sizeof(listenSocket)); //listenSocket 0 initial;
	listenSocket.sin_family = AF_INET;
	listenSocket.sin_addr.s_addr = htonl(INADDR_ANY);
	listenSocket.sin_port = htons(PORT);

	int listenFD = socket( AF_INET, SOCK_STREAM, 0);
	if(bind(listenFD, (struct sockaddr *) &listenSocket, sizeof(listenSocket)) ==-1){
		printf("Can not bind.\n");
		return -1;
	}
	
	//Listen new
	if(listen(listenFD, LISTEN_QUEUE_SIZE) == -1){
		printf("listen fail.\n");
		return -1;
	}
	printf("Waiting for clients...\n");

	//Client communication part
	while(1){
		struct sockaddr_in connectSocket, peerSocket; //Client informationg to bring
		int connectSocketLength = sizeof(connectSocket);
		int connectFD = accept(listenFD, (struct sockaddr *) &connectSocket, &connectSocketLength);
		//		
		getpeername(connectFD, (struct sockaddr *) &peerSocket, &connectSocketLength);

		printf("Client : %s\n", inet_ntoa(peerSocket.sin_addr));
		
		char buffer[BUFFER_SIZE] ={0};
		sprintf(buffer, "Hello, %s\n" , inet_ntoa(peerSocket.sin_addr));
		write(connectFD, buffer,strlen(buffer));
		close(connectFD);

	}
	close(listenFD);

	return 0;
}
