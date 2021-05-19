#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int n;
vector<pll> co;
vector<ll> cox,coy;
bool able(ll len) {
    for(ll x: cox) { x--;
        for(ll y: coy) { y--;
            int cnt=0;
            ll xe=x+len, ye=y+len;
            for(int j=0; j<n; j++) {
                if(x<co[j].first && co[j].first<xe && y<co[j].second && co[j].second<ye) cnt++;
            }
            if(cnt>=n-2) return true;
        }
    }
    return false;
}
int main() {
    scanf("%d", &n);
    ll x,y;
    for(int i=0; i<n; i++) {
        scanf("%lld%lld",&x,&y);
        cox.push_back(x);
        coy.push_back(y);
        co.push_back({x,y});
    }
    ll lo=0, hi=2e9+4;
    while(lo<hi) {
        ll len = (lo+hi)>>1;
        if(able(len)) hi=len;
        else lo=len+1;
    }
    printf("%lld", hi*hi);
    return 0;
}
