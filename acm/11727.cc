#include <stdio.h>
const int MOD = 10007;
int d[1001];
int f(int x) {
    if(x==0||x==1) return 1;
    if(d[x]>0) return d[x];
    return d[x] = (f(x-1) + 2*f(x-2))%MOD;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}
