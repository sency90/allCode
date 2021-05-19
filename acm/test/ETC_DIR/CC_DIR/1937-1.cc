#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int g[501][501], d[501][501];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int dfs(int x, int y) {
    if(d[x][y]) return d[x][y];
    for(int i=0; i<4; i++) {
        int nx=dx[i]+x, ny=dy[i]+y;
        if(nx<=0||ny<=0||nx>n||ny>n) continue;
        if(g[nx][ny]>g[x][y]) d[x][y]=max(d[x][y], dfs(nx,ny)+1);
    }
    return d[x][y];
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    int mx=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            mx = max(mx,dfs(i,j));
        }
    }
    printf("%d\n", mx+1);
    return 0;
}
