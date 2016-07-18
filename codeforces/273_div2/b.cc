#include <stdio.h>
long long combi(long long n) {
    return n*(n-1LL)/2LL;
}
int main() {
    long long n, m;
    scanf("%lld%lld",&n,&m);
    long long q=n/m, r= n%m;
    if(r==0) printf("%lld %lld\n", m*combi(q), combi(n-m+1));
    else printf("%lld %lld", r*combi(q+1)+(m-r)*combi(r), combi(n-m+1));
    return 0;
}
