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

    alarm(1); //1초 후에 나를 꺠워달라는 뜻임.
    //1초가 지나면 SIGALRM이라는 이벤트가 발생이 됨.
    //그런데 위에 signal()함수로 SIGALRM이 발생했을 때
    //뭘 할지를 customizing 했으므로 (handler함수를 실행시키도록 했음)
    //뭘 할지 등록한대로 실행되게 된다.
    //위에서는 handler함수를 실행시키도록 했음.

    while(1) {

    }

return 0; }
