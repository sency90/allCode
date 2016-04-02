#include <stdio.h>
#include <cstring>
using namespace std;
long long d[31], ans;
long long f(long long x) {
    if(d[x]>0) return d[x];
    if(x==0 || x==1) return d[x]=1LL;
    return d[x] = f(x-1) + f(x-2)*2LL;
}
int main() {
    long long n; scanf("%lld", &n);
    //memset(d, 0, sizeof(d));
    f(n);
    d[0]=1;
    if(n%2 == 0) ans = (d[n] + d[n/2] + 2*d[(n-2)/2])/2;
    else ans = (d[n] + d[(n-1)/2])/2;
    printf("%lld", ans);
    return 0;
}
