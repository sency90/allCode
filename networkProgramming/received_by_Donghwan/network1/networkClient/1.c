#include"../network1.h"

int main(int argc, char** argv){
	if (argc != 2){
		printf("Usage: %s IPv4-address\n", argv[0]);
		return -1;
	}

	//Connect Socket initial
	
	//Struct sockaddr_in{
	//	unsigned short sin_family;
	//	unsigned short sin_port;
	//	struct in_addr sin_addr;
	//	unsigned  char sin_zero[8];
	//}
	struct sockaddr_in connectSocket;
	//connectSocket[0]~size = 0 memory set
	memset(&connectSocket, 0, sizeof(connectSocket));
	//Address Family(Always AF_INET)	
	connectSocket.sin_family = AF_INET;
	
	//struct in_addr{
	//	unsigned int s_addr;
	//}
	//ASCII to Network(connectSocket.sin_addr.s_addr=IP)
	inet_aton(argv[1], &connectSocket.sin_addr.s_addr);
	//connectSocket.sin_port = short int from Host to Network  
	connectSocket.sin_port = htons(PORT);
	
	//int socket(int family,int type,int protocol)
	//Family=AF_INET(IPv4),SOCK_STREAM(Stream_socket),0)
	//SOCK_DGRAM = datagram socket(UDP)
	//SOCK_STREAM = stream soket(TCP,SCTP)
	int connectFD = socket(AF_INET, SOCK_STREAM, 0);
	
	//Connect
	//connect(int socket,const(struct sockaddr *) servaddr,socket_t addrn);
	//const(struct sockaddr *) servaddr : socket addr Struct
	//socket_t addren : Length 	
	//connectFD = socket() return;
	//return 0(OK),-1(Error)
	if(connect(connectFD, (struct sockaddr*) &connectSocket, sizeof(connectSocket)) == -1){
		printf("Can not connect.\n");
		return -1;
	}
	
	//
	else{
		char buffer[BUFFER_SIZE];
		int n = read(connectFD, buffer, BUFFER_SIZE); // n = num of read size
		printf("%d bytes read\n",n);
		buffer[n] = '\0';
		fputs(buffer,stdout);
	}

	close(connectFD);
	
	return 0;
}
