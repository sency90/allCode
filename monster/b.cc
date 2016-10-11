#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int,int> > plii;
int p[10001];
ll chk[10001][10001];
void init() { for(int i=0; i<=10000; i++) p[i]=i; }
int find(int x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
bool uni(int x, int y) {
    //if(x>y) swap(x,y);
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
        for(int i=1; i<=m; i++) {
            scanf("%d%d%lld",&x,&y,&w);
            if(x>y) swap(x,y);
            ed.push_back(plii(w,make_pair(x,y)));
        }
        sort(ed.begin(), ed.end(), cmp);

        memset(chk,0,sizeof(chk));
        init();
        for(auto &t: ed) {
            int x=t.second.first, y=t.second.second; ll w=t.first;
            if(x>y) swap(x,y);
            if(uni(x,y)) chk[x][y]=chk[y][x]=w;
        }
        ll ans = 0LL;
        int q; scanf("%d", &q);
        for(int i=0; i<q; i++) {
            int s,e; scanf("%d%d",&s,&e);
            if(s==e) continue;
            if(s>e) swap(s,e);
            ans+=chk[s][e];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
