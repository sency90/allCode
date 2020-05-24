#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> v;
int main() {
    ll n,k; scanf("%lld %lld",&n,&k);
    for(ll i=1; i*i<=n; i++) {
        if(n%i==0) {
            if(i*i==n) v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    sort(v.begin(), v.end());
    if(v.size()<k) puts("-1");
    else printf("%lld\n", v[k-1]);
    return 0;
}
