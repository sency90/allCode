#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int,int> > plii;
//const ll inf = 0x3f3f3f3f3f3f3fLL;
bool chk[10001][10001];
int p[10001];
void init() { for(int i=0; i<=10000; i++) p[i]=i; }
int find(int x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
bool uni(int x, int y) {
    if(x>y) swap(x,y);
    x=find(x); y=find(y);
    if(x==y) return false;
    else { p[y]=x; return true; }
}
bool cmp(const plii &lhs, const plii &rhs) {
    return lhs.first>rhs.first;
}
int main() {
    freopen("/Users/lian/allCode/monster/input.txt", "r", stdin);
    freopen("/Users/lian/allCode/monster/output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,m,x,y;
        ll w;
        scanf("%d%d",&n,&m);
        vector<plii> ed;
        for(ll i=1; i<=m; i++) {
            scanf("%d%d%lld",&x,&y,&w);
            if(x>y) swap(x,y);
            ed.push_back(plii(w,make_pair(x,y)));
        }
        sort(ed.begin(), ed.end(), cmp);

        ll ans = 0LL;
        memset(chk, false, sizeof(chk));
        int q; scanf("%d", &q);
        for(int i=0LL; i<q; i++) {
            int start,end; scanf("%d%d",&start,&end);
            if(start==end||start<=0||end<=0||start>n||end>n) continue;
            if(start>end) swap(start,end);
            if(chk[start][end]) continue;
            chk[start][end]=chk[end][start]=true;
            //ll minc=inf;
            init();
            ll minc=0LL;
            for(auto &t: ed) {
                ll w=t.first;
                int x=t.second.first, y=t.second.second;
                if(uni(x,y)) minc=w;
                if(find(start)==find(end)) break;
            }
            ans+=minc;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
