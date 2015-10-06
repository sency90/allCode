#include <stdio.h> //필요한 헤더를 추가하시오.
#include <stdlib.h> //for wait(), exit()
#include <unistd.h> //for fork()
#define N 4

int main() {
    pid_t pid[N];
    int child_status;

    for (int i = 0; i < N; i++) {
        if ( (pid[i] = fork()) == 0) { // child process는 fork되면 0을 return하므로
            exit(100+i);
        }
    }
    for (int i = 0; i < N; i++) {
        pid_t wpid = wait(&child_status);/*특정 child process가 끝날 때까지 기다리시오.*/
            /********/
            //child process가 exit로 종료되었을 때
            //각 child process의 exit 코드를 출력하시오. /********/
        if (WIFEXITED(child_status)) {
            printf("Child %d terminated with exit status %d\n", wpid, WEXITSTATUS(child_status));
        }
    }
    return 0;
}
