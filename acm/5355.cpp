#include <stdio.h>
int main() {
    int t; scanf("%d", &t);
    double x; char c;
    while(t--) {
        scanf("%lf", &x);
        while((c=getchar())!='\n' && c!=EOF && c!='\r') {
            if(c==' ') continue;
            if(c=='@') x*=3;
            else if(c=='%') x+=5;
            else if(c=='#') x-=7;
        }
        printf("%.2lf\n", x);
    }
    return 0;
}
