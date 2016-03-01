#include <stdio.h>
#include <string.h>
long long d[21];
long long f(int n) {
    if(n==0) return d[n] = 0;
    else if(n<=2) return d[n] = 1;
    if(d[n] > 0) return d[n];
    return d[n] = f(n-1) + f(n-2);
}
int main() {
    memset(d, 0, sizeof(d));
    int n; scanf("%d", &n);
    printf("%lld\n", f(n));
    return 0;
}
