//3번 예제 코드
//signal_handler.cpp
# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
# define N 4
int count = 0;
void child_handler(int signal) {
    int child_status;
    pid_t pid;
    while ( (pid = waitpid(-1, &child_status, WNOHANG)) > 0) {
        count--;
        printf("Received signal %d from process %d\n", signal, pid); }
}
int main() {
    //child_handler와 child process 종료 signal을 install 하시오.
    signal(SIGCHLD, child_handler);
    
    pid_t pid[N];
    int child_status;
    count = N;

    for (int i =0; i < N; i++) {
        if( (pid[i]=fork()) == 0) {
            exit(0);
        }
    }
    while (count > 0) {;}
    return 0;
}
