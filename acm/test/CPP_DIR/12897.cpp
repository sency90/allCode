#include <stdio.h>
const long long MOD = 1000000007;
long long three[100001];
int main() {
    int n;
    three[0] = 1;
    scanf("%d", &n);
    for(int i=1; i<=n+1; i++) {
        three[i] = (three[i-1]*3)%MOD;
    }
    printf("%lld", three[n]-1);
    return 0;
}
