#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> co;
vector<ll> cox,coy;
ll psx[100001], psy[100001];
const ll inf = 0x3f3f3f3f3f3f3f3f;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        cox.push_back(x);
        coy.push_back(y);
        co.push_back(pll(cox[i],coy[i]));
    }
    sort(cox.begin(), cox.end());
    sort(coy.begin(), coy.end());
    ll x = cox[cox.size()/2];
    ll y = coy[coy.size()/2];
    auto ABS = [](ll x) { return (x<0)?-x:x; };

    ll ans=0ll;
    for(int i=0; i<co.size(); i++) {
        ans+=ABS(co[i].first-x)+ABS(co[i].second-y);
    }
    printf("%lld\n", ans);
    return 0;
}
