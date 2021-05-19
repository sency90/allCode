#include <stdio.h>
#include <limits.h>
int main() {
    int m, n; scanf("%d %d", &m, &n);
    int tmp, mn=INT_MAX;
    long long sum=0;
    for(int i=1; i<=100; i++) {
        tmp = i*i;
        if(tmp>=m && tmp<=n) {
            if(mn > tmp) mn = tmp;
            sum += tmp;
        } else if(tmp > n) break;
    }
    if(mn==INT_MAX) puts("-1");
    else printf("%lld\n%d\n", sum, mn);
}
