#include <cstdio>
#include <cstring>
using namespace std;
char v[10][11];
bool chk[10][11];
int t, n, m, mx=0, nx, ny;
int dx[] = {-1,-1,-1,1,1,1,0,0};
int dy[] = {0,-1,1,0,-1,1,-1,1};
void dfs(int x, int y, int cnt) {
    if(mx < cnt) mx = cnt;
    for(int i=0; i<8; i++) {
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
        if(chk[nx][ny]) continue;
        printf("%d %d\n", nx, ny);
        dfs(nx,ny,cnt);
        chk[nx][ny] = true;
        if(v[nx][ny]=='.' && i<4) dfs(nx, ny, cnt+1);
    }
}
int main() {
    scanf("%d", &t);
    while(t--) {
        memset(chk, false, sizeof(chk));
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++) {
            scanf("%s", v[i]);
        }
        chk[0][0] = false;
        dfs(0,0,0);
        chk[0][0] = true;
        dfs(0,0,1);
        printf("%d\n", mx);
    }
    return 0;
}
