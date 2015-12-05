//4번 예제 코드
//bomb.cpp
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int beeps = 0;
void handler(int signal) {
//alarm signal handler를 완성하시오.
    printf("BEEP\n");

    if( ++beeps<5 ) {
        alarm(1);
    } else {
        printf("BOOM!!\n");
        exit(0);
    }
}
int main() {
//alarm signal을 전송하여 시한폭탄을 완성하시오.

    signal(SIGALRM, handler);

    alarm(1);

    while(1) {

    }

return 0; }
