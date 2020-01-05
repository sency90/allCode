#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<pii> g;
vector<int> v;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int l; scanf("%d", &l);
        v.clear();
        for(int j=0; j<l; j++) {
            int x; scanf("%d", &x);
            v.push_back(x);
        }
        reverse(v.begin(), v.end());
        if(is_sorted(v.begin(), v.end())) {
            g.emplace_back(v[0], v.back());
        }
    }

    ll cnt = (ll)n*n;
    sort(g.begin(), g.end());
    for(int i=0; i<g.size(); i++) {
        auto it = lower_bound(g.begin(), g.end(), pii(g[i].second,-1));
        cnt -= (ll)(g.end() - it);
    }
    printf("%lld", cnt);
    return 0;
}
