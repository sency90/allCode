#include <cstdio>
#include <cstring>
using namespace std;
const long long MOD = 1000000009LL;
const long long DMOD = MOD*2LL;
long long n, k;
long long d[1000010];
long long f(long long x) {
    if(x<0LL) return 0LL;
    else if(x==0LL) return d[x] = 1LL;
    if(d[x]!=-1LL) return d[x];
    return d[x] = (k*f(x-1)-2*f(x-5)+f(x-7)+DMOD)%MOD;
}
int main() {
    memset(d, -1, sizeof(d));
    scanf("%lld%lld", &n,&k);
    printf("%lld", f(n));
    return 0;
}
