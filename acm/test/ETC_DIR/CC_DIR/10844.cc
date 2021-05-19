#include <stdio.h>
const long long MOD = 1000000000LL;
long long d[101][10];
long long f(int x, int y) {
    if(x==1) {
        if(y==0) return 0;
        else return 1;
    }
    if(d[x][y] > 0) return d[x][y];
    if(y==0) d[x][y] = f(x-1,y+1);
    else if(y==9) d[x][y] = f(x-1,y-1);
    else d[x][y] = (f(x-1,y-1) + f(x-1,y+1))%MOD;
    return d[x][y];
}
int main() {
    int n;
    scanf("%d", &n);
    long long ans=0LL;
    for(int i=0; i<10; i++) {
        ans = (ans+f(n,i))%MOD;
    }
    printf("%lld", ans);
    return 0;
}
