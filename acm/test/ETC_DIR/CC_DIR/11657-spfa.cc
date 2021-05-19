#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
vector<pii> v[501];
bool chk[501];
int dist[501], cnt[501];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].pb(mp(y,w));
    }
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    q.push(1); chk[1]=true; dist[1]=0;
    while(!q.empty()) {
        int x=q.front(); q.pop();
        chk[x]=false;
        for(auto &p: v[x]) {
            int y=p.first, w=p.second;
            if(dist[y]>dist[x]+w) {
                dist[y]=dist[x]+w;
                if(++cnt[y]>=n) { puts("-1"); return 0; }
                if(!chk[y]) { q.push(y); chk[y]=true; }
            }
        }
    }
    for(int i=2; i<=n; i++) {
        printf("%d\n", dist[i]<inf?dist[i]:-1);
    }
    return 0;
}
