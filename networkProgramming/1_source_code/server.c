#include "header.h"
#define MAXPENDING 5

int main(int argc, char *argv[]) {
	
	int listenSockFD;
	char buffer[BUFFER_SIZE] = {0};

	int clientAddrLength;
	//서버의 listen 소켓 데이터 구조를 생성하시오
	struct sockaddr_in serverAddr, clientAddr;
    serverAddr.sin_family = AF_INET; // TCP
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Any incoming interface
	serverAddr.sin_port = htons(PORT); // PORT



	//listen file descriptor를 생성하시오
	if( (listenSockFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("error: serverSock creation\n");
		return -1; //error
	}

	//bind와 listen을 수행하시오
	if( bind(listenSockFD, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0 ) {
		printf("error: bind()\n");
		return -1; //error
	}

	if( listen(listenSockFD, MAXPENDING) < 0 ) {
		printf("error: listen()\n");
		return -1; //error
	}

	printf("Waiting for clients...\n");

	while(1) {
		//클라이언트와 통신할 소켓을 선언하시오
		//클라이언트의 접속 요청을 허가하시오
		clientAddrLength = sizeof(clientAddr);
		int connectedSockFD = accept(listenSockFD, (struct sockaddr *) &clientAddr, &clientAddrLength);

		//client에 Hello\n 문자열을 전송
		sprintf(buffer, "Hello\n");
		write(connectedSockFD, buffer, strlen(buffer));
		
		//클라이언트와의 접속을 끊으시오
		close(connectedSockFD);
	}

	//서버용 리슨 소켓을 닫으시오
	close(listenSockFD);
	
	return 0;
}
