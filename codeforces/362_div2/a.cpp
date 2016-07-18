#include <stdio.h>
int main() {
    int t,s,x;
    scanf("%d%d%d",&t,&s,&x);
    if(x<t) puts("NO");
    else if(t==x) puts("YES");
    else if(t<x && x<t+s) puts("NO");
    else if((x-t)%s==0 || (x-t-1)%s==0) puts("YES");
    else puts("NO");
    return 0;
}
