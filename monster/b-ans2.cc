#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int,int> > piii;
int p[10001], p_p[10001], cost[500001], chk[10001][10001];
void init() { for(int i=0; i<=10000; i++) p_p[i]=i; }
void init2(int n) { memcpy(p,p_p,(n+1)*sizeof(int)); }
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
bool cmp(const piii &lhs, const piii &rhs) {
    return cost[lhs.first]>cost[rhs.first];
}
int main() {
    freopen("/Users/lian/allCode/monster/input.txt", "r", stdin);
    freopen("/Users/lian/allCode/monster/output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    init();
    while(tc--) {
        int n,m,x,y,w;
        scanf("%d%d",&n,&m);
        vector<piii> ed;
        memset(chk,0,sizeof(chk));
        memset(cost,0,sizeof(cost));
        for(int i=1; i<=m; i++) {
            scanf("%d%d%d",&x,&y,&w);
            if(x>y) swap(x,y);
            if(!chk[x][y]) {
                chk[x][y]=i;
                ed.push_back(piii(i,make_pair(x,y)));
            }
            cost[chk[x][y]]=max(cost[chk[x][y]],w);
        }
        sort(ed.begin(), ed.end(), cmp);

        memset(chk,-1,sizeof(chk));
        ll ans = 0LL;
        int q; scanf("%d", &q);
        for(int i=0LL; i<q; i++) {
            int s,e; scanf("%d%d",&s,&e);
            if(s==e) continue;
            if(s>e) swap(s,e);
            if(chk[s][e]!=-1) {
                ans+=chk[s][e];
                continue;
            }
            init2(n);
            ll minc=0LL;
            for(auto &t: ed) {
                int idx=t.first, x=t.second.first, y=t.second.second;
                if(uni(x,y)) minc=cost[idx];
                if(find(s)==find(e)) break;
            }
            if(find(s)==find(e)) {
                chk[s][e]=minc;
                ans+=minc;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
