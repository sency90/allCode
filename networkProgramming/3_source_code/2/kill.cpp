#include <stdio.h> //필요한 헤더를 추가하시오.
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#define N 4
int main() {
    pid_t pid[N]; int child_status;
    for (int i = 0; i < N; i++) {
        if ( (pid[i] = fork()) == 0 ) {
            while(true);
        }
    }
    for (int i = 0; i < N; i++) {
        printf("Killing process %d\n", pid[i]);
        //kill 함수와 interrupt signal을 이용해 각 child process를 종료하시오.
        kill( pid[i], SIGINT );
    }
    for (int i = 0; i < N; i++) {
        pid_t wpid = wait(&child_status);/*불특정 child process가 끝날 때까지 기다리시오.*/ /********/
        //child process가 kill로 종료되었을 때 특정 문자열을 출력하시오. /********/
        if(!WIFEXITED(child_status)) {
            printf("Child process %d terminated by the kill function.\n", wpid);
        }
    }
    return 0;
}
