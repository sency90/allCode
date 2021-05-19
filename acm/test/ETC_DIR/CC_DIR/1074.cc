#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f(ll n, ll r, ll c) {
    if(n==0LL) return 0;
    ll sum = (1LL<<(n-1))*(1LL<<(n-1)),R,C;
    if(r<(1LL<<(n-1))) {
        R=r;
        if(c<(1LL<<(n-1))) sum*=0, C=c;
        else sum*=1, C=c-(1LL<<(n-1));
    } else {
        R=r-(1LL<<(n-1));
        if(c<(1LL<<(n-1))) sum*=2, C=c;
        else sum*=3, C=c-(1LL<<(n-1));
    }
    return sum + f(n-1,R,C);
}
int main() {
    ll n,r,c;
    scanf("%lld%lld%lld", &n,&r,&c);
    printf("%lld\n", f(n,r,c));
    return 0;
}
