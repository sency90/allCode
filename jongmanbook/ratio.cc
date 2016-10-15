#include <stdio.h>
const long long inf = 2e+9;
int rt(long long winGame, long long totalGame) {
    return winGame*100LL/totalGame;
}
int main() {
    int t;
    long long n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld",&n,&m);
        long long ratio = rt(m,n)+1;
        if(rt(m+inf,n+inf) < ratio) {
            puts("-1");
            continue;
        }

        long long l=0, r=inf, mid;
        for(int i=0; i<100; i++) {
            mid = (l+r)/2LL;
            if(rt(m+mid,n+mid) >= ratio) r=mid;
            else l=mid;
        }
        printf("%lld\n", r);
    }
    return 0;
}
