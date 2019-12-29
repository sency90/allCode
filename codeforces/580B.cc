#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll sum[100001];
vector<pll> v;
int main() {
    int n,d; scanf("%d%d",&n,&d);
    v.emplace_back(-1,-1);
    for(int i=0; i<n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        v.emplace_back(x,y);
    }
    sort(v.begin(), v.end());
    for(int i=1; i<v.size(); i++) {
        sum[i] = sum[i-1] + v[i].second;
    }

    ll ans=-1;
    for(int i=1; i<v.size(); i++) {
        auto it = lower_bound(v.begin()+i, v.end(), pll(v[i].first + d,-1));
        if(i <= (it-1) - v.begin()) ans = max(ans, sum[it-1 - v.begin()] - sum[i-1]);
    }
    printf("%lld", ans);
    return 0;
}
