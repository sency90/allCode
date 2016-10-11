#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<int> cox, coy;
vector<pll> co;
vector<pair<int, int> > xpi, ypi;
ll w;
bool cmpx(int i, int j) {
    return co[i].first<co[j].first;
    //if(co[i].first==co[j].first) return co[i].second<co[j].second;
    //else return co[i].first<co[j].first;
}
bool cmpy(int i, int j) {
    return co[i].second<co[j].second;
    //if(co[i].second==co[j].second) return co[i].first<co[j].first;
    //else return co[i].second<co[j].second;
}
int count(ll xs, ll xe, ll ys, ll ye) {
    ll x,y;
    int cnt=0;
    for(int i=0; i<co.size(); i++) {
        x=co[i].first, y=co[i].second;
        if((xs-w<=x&&x<=xs)&&(ys-w<=y&&y<=ye+w)) cnt++;
        else if((xe<=x&&x<=xe+w)&&(ys-w<=y&&y<=ye+w)) cnt++;
        else if((xs<x<xe)&&((ye<=y&&y<=ye+w)||(ys-w<=y&&y<=ys))) cnt++;
    }
    return cnt;
}
int main() {
    freopen("/Users/lian/allCode/monster/input.txt", "r", stdin);
    freopen("/Users/lian/allCode/monster/output.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        co.clear(); cox.clear(); coy.clear();
        int n,k;
        ll x,y;
        scanf("%d%d%lld",&n,&k,&w);
        for(int i=0; i<n; i++) {
            scanf("%lld%lld",&x,&y);
            co.push_back(make_pair(x,y));
            cox.push_back(i);
            coy.push_back(i);
        }
        sort(cox.begin(), cox.end(), cmpx);
        sort(coy.begin(), coy.end(), cmpy);

        xpi.clear(); ypi.clear();
        for(int i=0; i<cox.size(); i++) {
            for(int j=i+1; j<cox.size(); j++) {
                xpi.push_back(make_pair(i,j));
                ypi.push_back(make_pair(i,j));
            }
        }

        bool HA=false;
        ll xs,xe,ys,ye;
        for(int i=0; i<xpi.size(); i++) {
            for(int j=0; j<ypi.size(); j++) {
                xs=co[cox[xpi[i].first]].first; ys=co[coy[ypi[j].first]].second;
                xe=co[cox[xpi[i].second]].first; ye=co[coy[ypi[j].second]].second;
                if(n-count(xs,xe,ys,ye)<=k) {
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
