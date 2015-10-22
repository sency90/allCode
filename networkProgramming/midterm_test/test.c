#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <signal.h>

void fork9() {
    int child_status;
    pid_t pid;

    if ((pid=fork()) == 0) {
        printf("HC: hello from child\n");
        printf("c-pid: %d\n", pid);
    } else {
        printf("HP: hello from parent\n");
        wait(&child_status);

        printf("WIFEXITED??: %d\n", WIFEXITED(child_status));
        printf("p-pid: %d\n", pid);
        printf("CT: child has terminated\n");
    }
    printf("Bye\n");
    exit(-1);
}

int main() {
    fork9();
}
