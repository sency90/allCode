#include <cstdio>
using namespace std;
typedef long long ll;
ll ABS(ll x) { return (x<0LL)?-x:x; }
int main() {
    int tc; scanf("%d",&tc);
    while(tc--) {
        ll n,m,r0,c0,r,c,a,b;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&r0,&c0,&r,&c,&a,&b);
        printf("%lld\n",(ABS(r-r0)+a-1)/a+(ABS(c-c0)+b-1)/b);
    }
    return 0;
}
