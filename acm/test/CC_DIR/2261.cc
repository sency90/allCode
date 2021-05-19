#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
vector<pii> co;
inline int dist(pii &co1, pii &co2) {
    int x1=co1.first, x2=co2.first;
    int y1=co1.second, y2=co2.second;
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}
const int inf = 0x3f3f3f3f;
inline int brute_force(int s, int e) {
    int ret = inf;
    for(int i=s; i<e; i++) {
        for(int j=i+1; j<=e; j++) {
            ret = min(ret,dist(co[i],co[j]));
        }
    }
    return ret;
}
vector<pii> tmp;
inline bool cmp(const pii &lhs, const pii &rhs) {
    return lhs.second < rhs.second;
}
inline int dnc(int s, int e) {
    if(s>=e) return inf;
    else if(e-s<=3) return brute_force(s,e);

    register int m = (s+e)>>1;
    register int d = min(dnc(s,m),dnc(m+1,e));
    register int ss=m,ee=m;
    register int lo=s, hi=m;

    while(lo<=hi) {
        register int mid = (lo+hi)>>1;
        if((co[m].first-co[mid].first)*(co[m].first-co[mid].first)<d) hi=mid-1;
        else lo=mid+1;
    }
    ss=hi+1;
    lo=m+1; hi=e;
    while(lo<=hi) {
        register int mid = (lo+hi)>>1;
        if((co[m].first-co[mid].first)*(co[m].first-co[mid].first)<d) lo=mid+1;
        else hi=mid-1;
    }
    ee=lo-1;

    if(ss == ee) return d;

    tmp.clear();
    for(register int i=ss; i<=ee; i++) tmp.emplace_back(co[i]);
    sort(tmp.begin(), tmp.end(), cmp);

    for(register int i=0; i<tmp.size()-1; i++) {
        for(register int j=i+1; j<tmp.size(); j++) {
            if((tmp[j].second-tmp[i].second)*(tmp[j].second-tmp[i].second) < d) {
                d = min(d,dist(tmp[i], tmp[j]));
            }
            else break;
        }
    }
    return d;
}
int main() {
    register int n,x,y; scanf("%d", &n);
    for(register int i=0; i<n; i++) {
        scanf("%d%d",&x,&y);
        co.emplace_back(x,y);
    }
    sort(co.begin(), co.end());
    int sz = co.size();
    co.erase(unique(co.begin(), co.end()), co.end());
    if(sz != int(co.size())) puts("0");
    else printf("%d\n", dnc(0, co.size()-1));

    return 0;
}
