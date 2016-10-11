#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int> v[2002];
int r[2002][2002], p[2002], src, sink;
int main() {
    int n,m,x;
    scanf("%d%d",&n,&m);
    src=0; sink=n+m+1;
    for(int i=1; i<=n; i++) {
        if(!r[src][i]) { v[src].push_back(i); v[i].push_back(src); r[src][i]=1; } int cnt; scanf("%d", &cnt);
        for(int j=0; j<cnt; j++) {
            scanf("%d",&x);
            if(!r[i][x+n]) {
                v[i].push_back(x+n); v[x+n].push_back(i); r[i][x+n]=1;
                if(!r[x+n][sink]) {
                    v[x+n].push_back(sink); v[sink].push_back(x+n); r[x+n][sink]=1;
                }
            }
        }
    }

    int ans=0;
    while(true) {
        memset(p, -1, sizeof(p));
        queue<int> q;
        p[src]=src; q.push(src);
        //find augmenting path
        while(!q.empty() && p[sink]==-1) {
            int x=q.front(); q.pop();
            for(auto &y : v[x]) {
                if(p[y]!=-1 || r[x][y]<=0) continue;
                p[y]=x; q.push(y);
            }
        }
        if(p[sink]==-1) break;
        int mxflow=inf;
        for(int i=sink; i!=src; i=p[i]) mxflow=min(mxflow,r[p[i]][i]);
        for(int i=sink; i!=src; i=p[i]) {
            r[p[i]][i]-=mxflow;
            r[i][p[i]]+=mxflow;
        }
        ans+=mxflow;
    }
    printf("%d", ans);
    return 0;
}
