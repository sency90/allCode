#include <stdio.h>
int main() {
    int t,a,b,c;
    scanf("%d", &t);
    a = t/300;
    t%=300;
    b = t/60;
    t%=60;
    c = t/10;
    t%=10;
    if(t==0) printf("%d %d %d", a,b,c);
    else puts("-1");
    return 0;
}
