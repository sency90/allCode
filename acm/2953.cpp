#include <stdio.h>
int main() {
    int a,b,c,d,mx=0,idx;
    for(int i=1; i<=5; i++) {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a=a+b+c+d;
        if(mx < a) {
            mx = a;
            idx = i;
        }
    }
    printf("%d %d", idx, mx);
    return 0;
}
