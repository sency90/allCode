#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
    ll n,m;
    scanf("%lld%lld",&n,&m);
    if(n<=m) {
        printf("%lld\n", n);
        return 0;
    }
    n-=m;
    ll ans=m;
    ll tmp = (int )floor((sqrt(8*n+1)-1)/2);
    ans+=tmp+1;
    if(tmp*(tmp+1)/2 == n) ans--;
    printf("%lld\n", ans);
    return 0;
}
