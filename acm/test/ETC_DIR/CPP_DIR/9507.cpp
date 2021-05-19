#include <stdio.h>
#include <string.h>
long long d[68];
long long f(int x) {
    if(d[x]) return d[x];
    if(x < 2) return d[x] = 1LL;
    else if(x==2) return d[x] = 2LL;
    else if(x==3) return d[x] = 4LL;
    else return d[x] = f(x-1) + f(x-2) + f(x-3) + f(x-4);
}
int main() {
    memset(d, 0, sizeof(d));
    int t, n; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%lld\n", f(n));
    }
    return 0;
}
