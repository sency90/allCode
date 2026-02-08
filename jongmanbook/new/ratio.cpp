#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        ll n,m;
        cin >> n >> m;

        ll s = m*100LL/n;
        ll lo=0, hi=2e9+1;
        while(lo<=hi) {
            ll mid = (lo+hi)/2;
            ll x = (m+mid)*100LL/(n+mid);
            if(x>=s+1) hi=mid-1;
            else lo=mid+1;
        }

        if(hi==2e9+1) puts("-1");
        else printf("%lld\n", hi+1);
    }
    return 0;
}