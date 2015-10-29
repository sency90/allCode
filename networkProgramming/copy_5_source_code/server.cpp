# include "header.h"

//pthread를 위한 헤더를 추가하시오
# include <pthread.h>
void* workerThreadFunction(void *argument) {
    //readvn과 writevn을 이용해 클라이언트가 보낸 랜덤 넘버를 더해 되돌려보낸다
    int connfd = *(int*)argument;
    pthread_detach(pthread_self());
    free(argument);
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
    readvn(connfd, buf1, BUFFER_SIZE);
    readvn(connfd, buf2, BUFFER_SIZE);

    char result[BUFFER_SIZE];
    int res = atoi(buf1) + atoi(buf2);
    sprintf(result, "%d", res);
    writevn(connfd, (char*)&result, sizeof(result));

    //클라이언트 ID를 포함해 받은 메시지와 두 랜덤 넘버의 합을 출력하시오
    printf("%d + %d = %d\n", atoi(buf1), atoi(buf2), res);

    close(connfd);
    return NULL;
}


int main() {

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if( bind(listenfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("can not bind\n");
        return -1;
    }

    if( listen(listenfd, 12) == -1) {
        printf("listen fail\n");
        return -1;
    }

    printf("Waiting for clients...\n");

    //int *connfd = (int*)malloc(sizeof(int));
    //struct sockaddr_in clientAddr;
    //socklen_t clientAddrSize = sizeof(clientAddr);


    while(1) {
        struct sockaddr_in clientAddr;
        socklen_t clientAddrSize = sizeof(clientAddr);

        int *connfd = (int*)malloc(sizeof(int));
        *connfd = accept(listenfd, (struct sockaddr*)&clientAddr, &clientAddrSize);
        printf("Connection complete!\n");

        //클라이언트가 접속하면 쓰레드를 새로 생성하여 위 workerThreadFunction를 실행하도록 하시오
        pthread_t tid;

        pthread_create(&tid, NULL, workerThreadFunction, connfd);
        pthread_join(tid, NULL);
        //exit(0);
    }

    close(listenfd);
    return 0;
}
