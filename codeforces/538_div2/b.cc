#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<pii> v;
vector<int> g;
int main() {
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v.emplace_back(x,i);
    }
    sort(v.rbegin(), v.rend());
    int t = m*k;
    ll ans = 0;
    for(int i=0; i<t; i++) {
        ans += (ll)v[i].first;
        g.push_back(v[i].second);
    }
    printf("%lld\n", ans);
    sort(g.begin(), g.end());
    for(int i=m; i<t; i+=m) {
        printf("%d ", g[i]);
    }
    return 0;
}
