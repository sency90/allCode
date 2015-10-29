# include "header.h"
using namespace std;
//pthread를 위한 헤더를 추가하시오
void randomMessage (int id, int connectFD){
    //writevn, readvn으로 두 랜덤 넘버를 전송하고 그 합을 받으시오.
    //seed값으로 Process ID를 줬는데,
    //현재시각을 seed값으로 주면 fork 시간차가 별로 나지 않기 때문에
    //전부 같은 random seed값을 가져서 이렇게 하였다.
    unsigned int realID = getpid();
    srand(realID);

    char wBuffer[BUFFER_SIZE];
    char rBuffer[BUFFER_SIZE];
    int num1, num2;
    int result;

    for(int i=0; i<10; i++) {
        num1 = rand()%101+100;
        sprintf(wBuffer, "%d", num1);
        writevn(connectFD, wBuffer, sizeof(wBuffer));

        num2 = rand()%101+100;
        sprintf(wBuffer, "%d", num2);
        writevn(connectFD, wBuffer, sizeof(wBuffer));

        readvn(connectFD, rBuffer, BUFFER_SIZE);

        result = atoi(rBuffer);
        printf("[%d]CLIENT-ASK: %d + %d   =>   [%d]SERVER-ANSWER: %d\n", realID, num1, num2, realID, result);
    }

    close(connectFD);
    exit(result);
}

int main(int argc, char** argv) {

    //순차적으로 ID를 생성하면서 10개의 클라이언트 프로세스를 fork하시오.
    int pid;

    struct sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = inet_addr(argv[1]);//inet_aton(argv[1]);
    clientAddr.sin_port = htons(PORT);

    for(int i=0; i<10; i++) {
        //자식 프로세스일 경우 서버와 접속하여 통신을 10번 반복한 후 접속을 끊으시오.
        if((pid=fork())==0) {

            int connfd = socket(AF_INET, SOCK_STREAM, 0);
            if(connect(connfd, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) < 0 ) {
                printf("Error: Cannot connect with the Server\n");
                exit(-1);
            } //else {
            //printf("Connection Success!!\n");
            //}

            randomMessage(pid, connfd);

            break;
            //close(connfd);
            //exit(0);
        }
    }

    //부모 프로세스일 경우 10개의 자식 프로세스가 끝나기를 기다리시오
    int child_status;
    for(int i=0; i<10; i++) {
        pid_t wpid = wait(&child_status);
        if( WIFEXITED(child_status));
        //printf("----- Child %d terminated with exit status %d -----\n", wpid, WEXITSTATUS(child_status));
        else
            printf("----- Child %d terminated abnormally -----\n", wpid);
    }

    return 0;
}
