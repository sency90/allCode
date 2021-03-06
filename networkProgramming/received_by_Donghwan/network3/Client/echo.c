
#include"header.h"

#define TIME_OUT 5
void echoClient(int socketFD,const struct sockaddr* dataSocket,socklen_t dataSocketLength){
	
	char buffer[BUFFER_SIZE];

	while(1){
		printf("input: ");
		fgets(buffer,BUFFER_SIZE,stdin);
		fflush(stdin);

		sendto(socketFD,buffer,strlen(buffer),0,dataSocket,dataSocketLength);
		alarm(TIME_OUT);
		int n = recvfrom(socketFD,buffer,BUFFER_SIZE,0,NULL,NULL);
		alarm(0);		
		if(n<0) n=0;
		buffer[n]='\0';

		printf("Echo: ");
		fputs(buffer,stdout);
		fflush(stdout);
	}
}

