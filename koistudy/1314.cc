#include <cstdio>
using namespace std;
int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
bool chk[65][65][31], ans[65][65];
int cnt=0;
void dfs(int x, int y, int n) {
    chk[x][y][n] = true;
    if(n==0) {
        if(!ans[x][y]) cnt++;
        ans[x][y] = true;
        return;
    }
    for(int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if(!chk[nx][ny][n-1]) dfs(nx,ny,n-1);
    }
}
int main() {
    int n; scanf("%d", &n);
    dfs(n+1,n+1,n);
    printf("%d\n", cnt);
    return 0;
}
