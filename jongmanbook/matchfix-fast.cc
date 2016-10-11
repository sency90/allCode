#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
vector<vector<int> > v;
int p[114],win[12],cnt[12],src,sink;
int c[114][114], f[114][114];
void flow(int ff, int &ret) {
    while(true) {
        queue<int> q;
        memset(p, -1, sizeof(p));
        p[src]=src; q.push(src);
        while(!q.empty()&&p[sink]==-1) {
            int x=q.front(); q.pop();
            for(auto &y : v[x]) {
                if(p[y]!=-1||c[x][y]-f[x][y]<=0) continue;
                p[y]=x; q.push(y);
            }
        }
        if(p[sink]==-1) return;
        int mnf=inf;
        for(int i=sink; i!=src; i=p[i]) mnf=min(mnf,c[p[i]][i]-f[p[i]][i]);
        for(int i=sink; i!=src; i=p[i]) {
            f[p[i]][i]+=mnf; f[i][p[i]]-=mnf;
        }
        ret+=mnf;
    }
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,m; scanf("%d%d",&n,&m);
        v.clear(); v.resize(n+m+2, vector<int>());
        memset(win, 0, sizeof(win));
        memset(c, 0, sizeof(c));
        memset(cnt, 0, sizeof(cnt));
        src=n+m; sink=n+m+1;

        int mx=0;
        for(int i=0; i<n; i++) {
            scanf("%d", &win[i]);
            if(i==0) mx=win[0];
            else mx=max(mx, win[i]+1);
            v[i].push_back(sink); v[sink].push_back(i);
        }
        for(int i=n; i<n+m; i++) {
            int x,y; scanf("%d%d",&x,&y);
            cnt[x]++; cnt[y]++;
            v[src].push_back(i); v[i].push_back(src); c[src][i]++;
            v[i].push_back(x); v[x].push_back(i); c[i][x]++;
            v[i].push_back(y); v[y].push_back(i); c[i][y]++;
        }

        memset(f,0,sizeof(f));
        //determin lo,hi value
        int lo=mx,hi=win[0]+cnt[0],ans=-1,ff=0;
        for(int i=0; i<n; i++) {
            c[i][sink]=(lo-1)-win[i];
        } c[0][sink]++;

        for(int i=lo; i<=hi; i++) {
            if(i!=lo) for(int j=0; j<n; j++) c[j][sink]++;
            flow(inf,ff);
            if(ff==m) { ans=i; break; }
        }
        printf("%d\n", ans);
    }
    return 0;
}
