#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
vector<int> v[2002];
int r[2002][2002],src,sink,p[2002];
bool chk[2002];
void input(int x, int y, int w) {
    if(!r[x][y]) { v[x].push_back(y); v[y].push_back(x); r[x][y]=w; }
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    src=0; sink=n+m+1;
    for(int i=1; i<=n; i++) {
        int cnt; scanf("%d",&cnt);
        input(src,i,2);
        for(int j=0; j<cnt; j++) {
            int x; scanf("%d", &x);
            input(i,x+n,1);
            input(x+n,sink,1);
        }
    }

    int ans=0;
    while(true) {;
        queue<int> q;
        memset(p, -1, sizeof(p));
        q.push(src); p[src]=src;
        while(!q.empty() && p[sink]==-1) {
            int x = q.front(); q.pop();
            for(auto &y:v[x]) {
                if(p[y]!=-1||r[x][y]<=0) continue;
                p[y]=x; q.push(y);
            }
        }
        if(p[sink]==-1) break;
        int f=0x3f3f3f3f;
        for(int i=sink; i!=src; i=p[i]) f=min(f,r[p[i]][i]);
        for(int i=sink; i!=src; i=p[i]) {
            r[p[i]][i]-=f; r[i][p[i]]+=f;
        }
        ans+=f;
    }
    printf("%d", ans);
    return 0;
}
