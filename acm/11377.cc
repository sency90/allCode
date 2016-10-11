#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int> v[2002];
int r[2002][2002], src, sink;
bool chk[2002];
void input(int x, int y, int w) {
    if(!r[x][y]) { v[x].push_back(y); v[y].push_back(x); r[x][y]+=w; }
}
int dfs(int x, int mn) {
    if(chk[x]) return 0;
    chk[x]=true;
    if(x==sink) return mn;
    for(auto &y:v[x]) {
        if(chk[y]||r[x][y]<=0) continue;
        int f=dfs(y,min(mn,r[x][y]));
        if(f) {
            r[x][y]-=f; r[y][x]+=f;
            return f;
        }
    }
    return 0;
}
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    src=0, sink=n+m+1;
    k=(k>n)?n:k;
    for(int i=1; i<=n; i++) {
        int cnt; scanf("%d", &cnt);
        input(src,i,1);
        for(int j=0; j<cnt; j++){
            int x; scanf("%d", &x);
            input(i,x+n,1);
            input(x+n,sink,1);
        }
    }

    int ans=0, flow=inf;
    while(true) {
        memset(chk, false, sizeof(chk));
        int f=dfs(src, inf);
        if(f==0) break;
        ans+=f;
    }
    for(int i=1; i<=n; i++) r[src][i]=1;
    flow=k;
    while(true) {
        memset(chk, false, sizeof(chk));
        int f=dfs(src, flow);
        if(f==0) break;
        flow-=f;
        ans+=f;
        if(flow==0) break;
    }
    printf("%d", ans);
    return 0;
}
