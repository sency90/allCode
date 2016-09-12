#include <stdio.h>
const int MOD = 10007;
int mul(int x, int y) { return x*y%MOD; }
int spow(int x, int n) {
    if(n==0) return 1;
    int ret = spow(x, n/2);
    ret = mul(ret,ret);
    if(n&1) return ret*x%MOD;
    else return ret;
}
int f(int n, int k) {
    int ret=1;
    for(int i=0; i<k; i++) {
        ret = mul(ret,n-i);
        ret = mul(ret,spow(i+1,MOD-2));
    }
    return ret;
}
int main() {
    int n, k; scanf("%d%d",&n,&k);
    printf("%d", f(n,k));
    return 0;
}
