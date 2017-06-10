#include <stdio.h>
#include <queue>
using namespace std;
int v[104][104];
bool chk[104][104][4];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int turn[][2] = {{2,3},{3,2},{1,0},{0,1}};
int ex, ey, er, sx, sy, sr;
struct Info{
    int x, y, dir, cnt;
    Info(int xx, int yy, int ddir, int ccnt) {
        x = xx; y = yy; dir = ddir; cnt = ccnt;
    }
};
queue<Info> q;
int main() {
    int n, m, x, y, nx, ny, dir, cnt, ans=0x3f3f3f3f;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    scanf("%d %d %d", &sx, &sy, &sr);
    scanf("%d %d %d", &ex, &ey, &er);
    sr--; er--;
    q.push(Info(sx, sy, sr, 0));
    chk[sx][sy][sr] = true;
    while(!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        dir = q.front().dir;
        cnt = q.front().cnt;
        q.pop();
        if(x==ex && y==ey && dir==er) {
            if(ans > cnt) ans = cnt;
            continue;
        }
        for(int i=0; i<2; i++) {
            if(chk[x][y][turn[dir][i]]) continue;
            chk[x][y][turn[dir][i]] = true;
            q.push(Info(x,y,turn[dir][i],cnt+1));
        }
        for(int i=1; i<=3; i++) {
            nx = x+dx[dir]*i;
            ny = y+dy[dir]*i;
            if(nx<1||ny<1||nx>n||ny>m) continue;
            if(v[nx][ny]) break;
            if(chk[nx][ny][dir]) continue;
            chk[nx][ny][dir] = true;
            q.push(Info(nx,ny,dir,cnt+1));
        }
    }
    printf("%d", ans);
    return 0;
}
