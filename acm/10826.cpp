#include <stdio.h>
long long d[10001];
long long f(int x) {
    if(x==0) return 0;
    if(x==1) return 1;
    if(d[x] > 0) return d[x];
    return d[x] = f(x-1) + f(x-2);
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", f(n));
    return 0;
}
