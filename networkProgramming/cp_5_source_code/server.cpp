# include "header.h"

//pthread를 위한 헤더를 추가하시오
# include <pthread.h>
void* workerThreadFunction(void *argument) {
    //readvn과 writevn을 이용해 클라이언트가 보낸 랜덤 넘버를 더해 되돌려보낸다
    int connfd = *(int*)argument;
    pthread_detach(pthread_self());
    free(argument);
    char buf1, buf2;
    readvn(connfd, (char*)&buf1, BUFFER_SIZE);
    readvn(connfd, (char*)&buf2, BUFFER_SIZE);

    char result = buf1 + buf2;
    writevn(connfd, (char*)&result, sizeof(result));

    //클라이언트 ID를 포함해 받은 메시지와 두 랜덤 넘버의 합을 출력하시오
    printf("%d + %d = %d", buf1, buf2, result);

    close(connfd);
    return NULL;
}


int main() {

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if( bind(listenfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        printf("can not bind\n");
        return -1;
    }

    if( listen(listenfd, 12) == -1) {
        printf("listen fail\n");
        return -1;
    }

    printf("Waiting for clients...\n");

    //int *connfd = (int*)malloc(sizeof(int));
    struct sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);


    while(1) {
        //struct sockaddr_in clientAddr;
        //socklen_t clientAddrSize = sizeof(clientAddr);

        int *connfd = (int*)malloc(sizeof(int));
        *connfd = accept(listenfd, (struct sockaddr*)&clientAddr, &clientAddrSize);

        //클라이언트가 접속하면 쓰레드를 새로 생성하여 위 workerThreadFunction를 실행하도록 하시오
        pthread_t tid;

        pthread_create(&tid, NULL, workerThreadFunction, connfd);
        pthread_join(tid, NULL);
        //exit(0);
    }

    return 0;
}
