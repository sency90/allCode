#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    ll a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(a>c||b>d) return 0&puts("-1");
    ll i,xi,yi,x,y;

    ll inf = 0x3f3f3f3f3f3f3f3f;
    ll mn = inf;
    for(i=0; (1LL<<i)*a<=c && (1LL<<i)*b<=d; i++) {
        x=c-a*(1LL<<i);
        y=d-b*(1LL<<i);
        if(x==y) {
            ll s = 1LL<<i, cnt=0;
            while(x) {
                if(x-s>=0) {
                    x-=s;
                    cnt++;
                } else s>>=1;
            }
            mn = min(mn, cnt+i);
        }
    }
    if(mn>=inf) puts("-1");
    else printf("%lld", mn);
    return 0;
}
