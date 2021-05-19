#include <stdio.h>
const int MOD = 10007;
int d[1001][10];
int f(int x, int y) {
    if(y==0) return 1;
    else if(x==1) return 1;
    if(d[x][y] > 0) return d[x][y];
    int &ret = d[x][y];
    for(int i=0; i<=y; i++) {
        ret = (ret+f(x-1,i))%MOD;
    }
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i=0; i<10; i++) {
        ans = (ans + f(n,i))%MOD;
    }
    printf("%d\n", ans);
    return 0;
}
