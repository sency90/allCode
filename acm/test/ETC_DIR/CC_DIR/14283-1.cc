#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int r[501][501], p[501];
vector<int> v[501];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        ed.push_back({{x,y},z});
        if(!r[x][y]) {
            v[x].push_back(y);
            v[y].push_back(x);
        }
        r[x][y]=+z;
        r[y][x]=r[x][y];
    }
    int src,snk; scanf("%d%d", &src,&snk);
    for(int i=0; i<m; i++) {
        for(auto )
    }

    int ans=0;
    while(true) {
        memset(p,-1,sizeof(p));
        queue<int> q;
        q.push(src); p[src]=src;
        while(!q.empty() && p[snk]==-1) {
            int x = q.front(); q.pop();
            for(int y: v[x]) {
                if(p[y]==-1 && r[x][y]>0) {
                    p[y]=x;
                    q.push(y);
                }
            }
        }
        if(p[snk]==-1) break;
        int mnf=0x3f3f3f3f;
        for(int i=snk; i!=src; i=p[i]) mnf = min(mnf, r[p[i]][i]);
        for(int i=snk; i!=src; i=p[i]) {
            r[p[i]][i]-=mnf;
            r[i][p[i]]+=mnf;
        }
        ans+=mnf;
    }
    printf("%d", ans);
    return 0;
}
