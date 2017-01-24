#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,m,k;
ll chk(ll z) {
    ll ret = 0;
    ll a = max(1-k+z,1LL), b=max(z-n+k,1LL);
    ll alen,blen;
    if(a==1LL) {
        alen=z;
        ret+=k-z;
    } else alen=k;
    if(b==1LL) {
        blen=z;
        ret+=n-k+1-z;
    } else blen=n-k+1;

    ret+=(a+z)*alen/2+(b+z)*blen/2-z;
    return ret;
}
int main() {
    scanf("%lld %lld %lld",&n,&m,&k);
    ll lo=1LL, hi=m;
    if(m==1) return 0&puts("1");
    if(n==1) return 0&printf("%lld\n",m);
    while(lo<hi) {
        ll mid = (lo+hi)>>1;
        if(chk(mid)<=m) lo=mid+1;
        else hi=mid;
    }
    printf("%lld\n", lo-1ll);
    return 0;
}
