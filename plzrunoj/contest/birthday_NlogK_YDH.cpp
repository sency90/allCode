#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = ll(1e9)+7LL;
int main() {
    int n,k;
    ll x,ans=0LL;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld%d",&x,&k);
        for(ll mul=1LL; k; mul*=x, k>>=1) {
            if(mul>=mod) mul%=mod;
            if(k&1) {
                ans+=mul;
                if(ans>=mod) ans%=mod;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
