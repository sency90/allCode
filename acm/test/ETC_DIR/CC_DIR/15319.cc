#include <cstdio>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
int main() {
    ll ans=0,x,k;
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld%lld",&x,&k);
        for(ll p=1LL; k; k>>=1, p*=x) {
            if(k&1LL) ans+=p;
            if(ans>=MOD) ans%=MOD;
            if(p>=MOD) p%=MOD;
        }
    }
    printf("%lld", ans);
    return 0;
}
