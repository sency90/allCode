# include "header.h"
using namespace std;
//pthread를 위한 헤더를 추가하시오
void randomMessage (int id, int connectFD){
    //writevn, readvn으로 두 랜덤 넘버를 전송하고 그 합을 받으시오.
    srand(time(0));
    char wBuffer = rand()%101+100;
    char testA = wBuffer;
    writevn(connectFD, (char*)&wBuffer, sizeof(wBuffer));

    wBuffer = rand()%101+100;
    char testB = wBuffer;
    writevn(connectFD, (char*)&wBuffer, sizeof(wBuffer));

    char testResult = testA + testB;
    char rBuffer;
    int rBufferSize;
    readvn(connectFD, (char*)&rBuffer, BUFFER_SIZE);

    if( testResult == rBuffer ) { //assertion
        printf("the same!!\n");
    } else {
        printf("Error\n");
        printf("rBuffer: %d\n", rBuffer);
        printf("Test result: %d\n", testResult);
        printf("rBuffer must be returned like test result!\n\n");
    }



}

int main(int argc, char** argv) {

    //순차적으로 ID를 생성하면서 10개의 클라이언트 프로세스를 fork하시오.
    int pid;
    for(int i=0; i<10; i++) {
        //자식 프로세스일 경우 서버와 접속하여 통신을 10번 반복한 후 접속을 끊으시오.
        if((pid=fork())==0) {

            struct sockaddr_in clientAddr;
            clientAddr.sin_family = AF_INET;
            clientAddr.sin_addr.s_addr = inet_addr(argv[1]);//inet_aton(argv[1]);
            clientAddr.sin_port = PORT;

            int connfd = socket(AF_INET, SOCK_STREAM, 0);
            if(connect(connfd, (struct sockaddr*)&connfd, sizeof(connfd)) == -1) {
                printf("Error: Cannot connect with the Server\n");
                exit(-1);
            } else {
                printf("Connection Success!!\n");
            }

            close(connfd);
            exit(0);
        }
    }

    //부모 프로세스일 경우 10개의 자식 프로세스가 끝나기를 기다리시오
    int child_status;
    for(int i=0; i<10; i++) {
        pid_t wpid = wait(&child_status);
        if( WIFEXITED(child_status))
            printf("Child %d terminated with exit status %d\n", wpid, WEXITSTATUS(child_status));
        else
            printf("Child %d terminated abnormally\n", wpid);
    }

    return 0;
}
