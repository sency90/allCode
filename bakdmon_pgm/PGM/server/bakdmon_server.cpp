#include "bakdmon_server.h"
using namespace std;
int fprintlog(FILE *logfp, const char *format, ... ) {
    va_list args;
    va_start(args, format); vfprintf(logfp, format, args); va_end(args);
    va_start(args, format); vfprintf(stdout, format, args); va_end(args);
    return 0;
}
void chkEvent() {
    ifstream ifs(dirInfo.eventDir.c_str());
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); cerr.tie(0);
    int pid = fork();
    printf("pid = [%d]\n", pid);

    //FILE *fp = fopen("today.LOG", "w+");
    if(pid < 0) printf("ERROR[001]: FORK ERROR\n");
    else if(pid > 0) { //parent process
        printf("child process: [%d], parent process: [%d]\n", pid, getpid());
        exit(0);
    } else { //child process
        printf("process: [%d]\n", getpid());
    }

    //signal(SIGHUP, SIG_IGN);
    close(0); close(1); close(2); //close stdin, stdout, stderr
    setsid(); //separating this terminal and the daemon process
    chdir("/");

    init();
    while(1) chkEvent();
    return 0;
}



