#include <stdio.h>
#include <string.h>
long long d[101];
long long f(int x) {
    if(d[x] > 0) return d[x];
    else if(x==0) return 0;
    else if(x==1 || x==2 || x==3) return d[x] = 1;
    else if(x==4) return d[x] = 2;
    return d[x] = f(x-1) + f(x-5);
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
