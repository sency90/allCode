#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
struct Info{
    Info(){}
    Info(ll x, ll y, ll d):x(x), y(y), d(d) {}
    ll x, y, d;
};
vector<Info> v;
vector<ll> dist;
int main() {
    int n,m; scanf("%d%d",&n,&m);
    dist.clear(); dist.resize(n+1, inf);
    for(int i=0; i<m; i++) {
        ll x,y,d; scanf("%lld%lld%lld",&x,&y,&d);
        v.emplace_back(x,y,d);
    }

    dist[1]=0LL;
    for(int i=0; i<n; i++) {
        for(auto &p: v) {
            if(dist[p.x]>=inf) continue;
            if(dist[p.y]>dist[p.x]+p.d) {
                dist[p.y] = dist[p.x]+p.d;
                if(i==n-1) return 0& puts("-1");
            }
        }
    }

    for(int i=2; i<=n; i++) {
        if(dist[i]>=inf) puts("-1");
        else printf("%lld\n", dist[i]);
    }
    return 0;
}
