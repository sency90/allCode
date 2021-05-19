#include <stdio.h>
bool chk[1000001];
int main() {
    long long n, x;
    scanf("%lld%lld",&n,&x);
    if(n==1LL) {
        if(x==0LL) puts("1");
        else puts("-1");
        return 0;
    }
    if(x>(n-1LL)*(n-2LL)/2LL) {
        puts("-1");
        return 0;
    }

    int h = n-1;
    printf("%d ", h);
    for(int i=h-1; i>=1; i--) {
        if(x>=i) {
            printf("%d ", h-i);
            chk[h-i] = true;
            x-=i;
        } else {
            if(x==0LL) break;
            else i=x+1;
        }
    }
    printf("%d ", h+1);

    for(int i=n-2; i>=1; i--) {
        if(!chk[i]) printf("%d ", i);
    }
    return 0;
}
