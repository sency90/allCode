#include <stdio.h>
int main() {
    char c;
    double x;
    while((c=getchar())!='\n' && c!=EOF && c!='\r') {
        if(c=='A') x = 4;
        else if(c=='B') x = 3;
        else if(c=='C') x = 2;
        else if(c=='D') x = 1;
        else if(c=='F') x = 0;
        else if(c=='+') x+=0.3;
        else if(c=='-') x-=0.3;
        else if(c==' ') continue;
    }
    printf("%.1lf", x);
}
