#include"header.h"

int main(int argc,char** argv){
	if(argc!=2){
		printf("Usage %s IPv4-address\n",argv[0]);
		return -1;
	}
	
	struct sockaddr_in dataSocket;
	memset(&dataSocket,0,sizeof(dataSocket));
	dataSocket.sin_family = AF_INET;
	inet_aton(argv[1],(struct in_addr*) &dataSocket.sin_addr.s_addr);
	dataSocket.sin_port = htons(PORT);

	int socketFD = socket(AF_INET,SOCK_DGRAM,0);

	echoClient(socketFD,(struct sockaddr*)& dataSocket,sizeof(dataSocket));

	return 0;
}
