#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<ll> cox, coy;
vector<pll> co;
vector<pair<int, int> > xpi, ypi;
ll w;
int n,k;
int count(ll xs, ll xe, ll ys, ll ye) {
    ll x,y;
    int cnt=0, cnt2=0;
    for(int i=0; i<co.size(); i++) {
        x=co[i].first, y=co[i].second;
        if((xs-w<=x&&x<=xs)&&(ys-w<=y&&y<=ye+w)) cnt++;
        else if((xe<=x&&x<=xe+w)&&(ys-w<=y&&y<=ye+w)) cnt++;
        else if((xs<x&&x<xe)&&((ye<=y&&y<=ye+w)||(ys-w<=y&&y<=ys))) cnt++;
        else if(!(x<xs-w||xe+w<x)) cnt2++;
    }
    if(cnt2<=k) return cnt+cnt2;
    else return n+1;
}
int main() {
    freopen("/Users/lian/allCode/monster/input.txt", "r", stdin);
    freopen("/Users/lian/allCode/monster/output.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        set<pll> chk;
        co.clear(); cox.clear(); coy.clear();
        ll x,y;
        int cnt=0;
        scanf("%d%d%lld",&n,&k,&w);
        for(int i=0; i<n; i++) {
            scanf("%lld%lld",&x,&y);
            if(chk.count(make_pair(x,y))) {
                cnt++;
                continue;
            }
            chk.insert(make_pair(x,y));
            co.push_back(make_pair(x,y));
            cox.push_back(x);
            coy.push_back(y);
        }
        n-=cnt;
        sort(cox.begin(), cox.end());
        sort(coy.begin(), coy.end());

        xpi.clear(); ypi.clear();
        for(int i=0; i<cox.size(); i++) {
            for(int j=i; j<cox.size(); j++) {
                xpi.push_back(make_pair(i,j));
                ypi.push_back(make_pair(i,j));
            }
        }

        bool HA=false;
        ll xs,xe,ys,ye;
        for(int i=0; i<xpi.size(); i++) {
                xs=cox[xpi[i].first];
                xe=cox[xpi[i].second];
            for(int j=0; j<ypi.size(); j++) {
                ys=coy[ypi[j].first];
                ye=coy[ypi[j].second];
                if(count(xs,xe,ys,ye)==n) {
                    HA=true;
                    break;
                }
            }
            if(HA) break;
        }
        if(HA) puts("YES");
        else puts("NO");
    }
    return 0;
}
