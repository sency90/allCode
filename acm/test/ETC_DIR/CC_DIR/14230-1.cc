#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
pll operator-(const pll &lhs, const pll &rhs) {
    return pll(lhs.first-rhs.first, lhs.second-rhs.second);
}
ll operator*(const pll &lhs, const pll &rhs) {
    return lhs.first*rhs.first + lhs.second*rhs.second;
}
vector<pll> co;
struct Line{
    pll dir, sco;
    Line():dir(0,0),sco(0,0){}
    Line(pll sco, pll dir):sco(sco),dir(dir){}
};
vector<Line> line;
bool isinaline(const Line &line, const pll &co) {
    ll x=co.first-line.sco.first, y=co.second-line.sco.second;
    if(line.dir.first==0 && line.dir.second==0) return true;
    else if(line.dir.first==0) return y==0;
    else if(line.dir.second==0) return x==0;
    else return (x*line.dir.second == -1LL*y*line.dir.first);
}
bool isOrthogonal(const Line &l, const Line &r) {
    return (l.dir.first*r.dir.first + l.dir.second*r.dir.second == 0);
}
vector<vector<int>> lineihasco;
vector<int> linecnt;
int cnt[51];
int main() {
    int n; scanf("%d", &n);
    int idx=0;
    for(int i=0; i<n; i++) {
        ll x,y; scanf("%lld%lld",&x,&y);
        sort(co.begin(), co.end());
        auto it = lower_bound(co.begin(), co.end(), pll(x,y));
        if(it == co.end()) {
            cnt[idx++]++;
            co.emplace_back(pll(x,y));
        } else if(*it == pll(x,y)) {
            cnt[it-co.begin()]++;
            continue;
        } else {
            cnt[idx++]++;
            co.emplace_back(pll(x,y));
        }
    }
    n=idx;
    if(n==1||n==2) return 0&printf("%d\n", n);

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            line.emplace_back(Line(co[i],co[i]-co[j]));
        }
    }
    lineihasco.resize(line.size(),vector<int>());
    linecnt.resize(line.size(),0);
    for(int i=0; i<line.size(); i++) {
        for(int j=0; j<n; j++) {
            if(isinaline(line[i],co[j])) {
                lineihasco[i].emplace_back(j);
                linecnt[i]+=cnt[j];
            }
        }
    }
    int mx=1;
    for(int i=0; i<line.size(); i++) {
        for(int j=i+1; j<line.size(); j++) {
            if(isOrthogonal(line[i], line[j])) {
                int cc=0;
                for(int p: lineihasco[i]) {
                    for(int q: lineihasco[j]) {
                        if(p==q) cc+=cnt[p];
                    }
                }
                mx = max(mx,int(linecnt[i]+linecnt[j])-cc);
            }
        }
    }
    printf("%d\n", mx);
}
