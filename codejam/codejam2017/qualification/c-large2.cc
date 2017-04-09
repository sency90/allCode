#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
vector<pii> v;
void mktree(ll k) {
    while(k!=1) {
        if(k%2==1) v.emplace_back(pll(0,1));
        else v.emplace_back(pll(1,0));
        k/=2LL;
        printf("%lld\n", k);
    }
}
inline ll getLeft(ll x) {
    if(x==0||x==1) return 0;
    return (x-1LL)-(x-1LL)/2LL;
}
inline ll getRight(ll x) {
    if(x==0||x==1) return 0;
    return (x-1LL)/2LL;
}
ll getans(ll x) {
    puts("X start");
    for(int i=v.size()-1; i>=0; i--) {
        if(v[i].first) x=getLeft(x);
        else x=getRight(x);
        printf("%lld\n", x);
    }
    return x;
}
int main() {
    freopen("in_sam.txt", "r", stdin);
    //freopen("result.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        ll n, k; scanf("%lld %lld", &n,&k);
        v.clear();
        mktree(k);
        ll ans = getans(n);
        printf("ans: %lld\n", ans);
        printf("Case #%d: %lld %lld\n",z,getLeft(ans),getRight(ans));
    }
    return 0;
}
