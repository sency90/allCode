#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<int> v;
vector<int> g;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int l; scanf("%d", &l);
        int mn=0x3f3f3f3f, mx=-1;
        bool isAsc = false;
        for(int j=0; j<l; j++) {
            int x; scanf("%d", &x);
            mx = max(x,mx);
            mn = min(x,mn);
            if(j!=0 && mn<x) isAsc=true;
        }
        if(!isAsc) {
            v.push_back(mn);
            g.push_back(mx);
        }
    }
    sort(v.begin(), v.end());
    sort(g.begin(), g.end());
    ll cnt=(ll)n*n;
    for(int i=0; i<v.size(); i++) {
        auto it = upper_bound(g.begin(), g.end(), v[i]);
        cnt -= (ll)(it-g.begin());
    }
    printf("%lld\n", cnt);
    return 0;
}
