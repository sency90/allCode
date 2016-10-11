#include <cstdio>
using namespace std;
long long modular_power(long long x, long long k, long long mod) {
    if(k==0) return 1LL;
    long long ret = modular_power(x,k>>1,mod);
    ret=ret*ret%mod;
    if(k&1LL) ret=ret*x%mod;
    return ret;
}
int main() {
    long long x,k,mod;
    scanf("%lld%lld%lld",&x,&k,&mod);
    printf("%lld\n",modular_power(x,k,mod));
    return 0;
}
