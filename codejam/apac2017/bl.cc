#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
bool chk(ll x, ll tmp, ll &cnt) {
    while(x>=tmp) {
        if(x%tmp==1LL) cnt++;
        else return false;
        x/=tmp;
    }
    if(x==1LL) cnt++;
    else return false;
    return true;
}
int main() {
    freopen("./input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        set<int> s;
        ll x; scanf("%lld", &x);
        for(ll i=2LL; i*i<=x; i++) s.insert(i), s.insert(x/i);
        s.insert(x);
        ll ans = 0LL, mx=0LL;
        for(auto p: s) {
            ll tmp=(ll)p-1LL;
            if(tmp==1LL) continue;

            ll cnt=0LL;
            if(chk(x,tmp,cnt)) {
                if(mx<cnt) {
                    mx=cnt;
                    ans=tmp;
                }
            }
        }
        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}
