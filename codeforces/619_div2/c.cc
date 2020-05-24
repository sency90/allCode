#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        ll n,m; scanf("%lld%lld", &n,&m);
        if(m==0) puts("0");
        else {
            ll k = n-m;
            if(k%(m+1LL) == 0LL) {
                ll t = k/(m+1LL);
                printf("%lld\n", n*(n+1)/2 - ((t*(t+1)/2)*(m+1LL)));
            } else {
                ll x =(ll)(k/(m+1LL))+1LL;
                ll a = k + (1-x)*(m+1);
                ll b = -k + x*(m+1);

                printf("%lld\n", n*(n+1)/2 - (x*(x+1)/2 * a + (x-1)*x/2 * b));
            }
        }
    }
    return 0;
}
