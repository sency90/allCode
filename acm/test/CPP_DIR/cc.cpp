#include <stdio.h>
int k;
long long d[100], a[100];
long long f(int x) {
    if(x==1) return a[1];
    if(d[x] > 0) return d[x];
    if(x <= k) return a[x-1]^f(x-1);
    return d[x] = f(x-1)^f(x-2);
}
int main() {
    scanf("%d", &k);
    for(int i=1; i<=k; i++) {
        scanf("%lld", &a[i]);
    }
    long long l, r, ans;
    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        scanf("%lld %lld", &l, &r);
        ans = f(l);
        for(int j=l+1; j<=r; j++) {
            ans ^= f(j);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
