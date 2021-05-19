#include <cstdio>
#include <cassert>
using namespace std;
typedef long long ll;
ll print(ll x) {
    printf("ret: %lld\n",x);
    return x;
}
ll getodd(ll k, ll x) {
    if(x<0||k>x) return 0;
    else if(k==x) return 1;
    else if(k==0) return x+1;

    ll i=1,pi=-1,ret=0ll;
    for(; k*(1ll<<i)<x; i++) {
        ret+=(1ll<<(i-1));
        pi=i;
    }
    if(pi<0) return 0;
    ll r = x%(k*(1ll<<pi));
    if(r <= (1ll<<pi)-1ll) return ret+r+1ll;
    else return ret+(1ll<<pi);
}
ll geteven(ll k, ll x) {
    if(x<0||k>x) return 0;
    else if(k==x) return 1;
    else if(k+1==x) return 2;
    else if(k==0) return x+1;

    ll i=1,pi=-1,ret=0ll;
    for(;k*(1ll<<i)<x; i++) {
        ret+=(1ll<<(i-1));
        pi=i;
    }
    if(pi<0) return 0;
    printf("%lld", pi);
    assert(pi>=1);
    ll r = x-k*(1ll<<pi);
    if(r <= (1ll<<(pi-1))) return ret+r;
    else return ret+(1ll<<(pi-1));

    printf("[x]:%lld ret:%lld r:%lld pi:%lld\n", x,ret,r,pi);
    printf("k*(2^pi): %lld,   k*(2^(pi+1)): %lld\n", k*(1ll<<pi), k*(1ll<<(pi+1)));
    if(r <= (1ll<<(pi+1))-1ll) return print(ret+r*2+1ll);
    else return print(ret+(1ll<<(pi+1)));
}
int main() {
    ll k,a,b;
    scanf("%lld%lld%lld",&k,&a,&b);
    if(k&1) printf("%lld\n", getodd(k,b)-getodd(k,a-1ll));
    else printf("%lld\n", geteven(k,b)-geteven(k,a-1ll));
    return 0;
}
