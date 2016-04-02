#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
int chk[9][9];
int t, n, m, sx, sy, ex, ey;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool hasAns;
queue<pair<int,int> > q;
void dfs(int x, int y, int cnt) {
    if(hasAns) return;
    chk[x][y] = true;
    q.push(make_pair(x,y));
    if(cnt==1) {
        if(x==ex && y==ey) {
            hasAns = true;
            while(!q.empty()) {
                printf("%d %d\n", q.front().first, q.front().second);
                q.pop();
            }
        } else hasAns = false;
        return;
    }
    int nx, ny;
    for(int i=0; i<4; i++) {
        if(hasAns) return;
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx<=0 || ny<=0 || nx>n || ny>m) continue;
        if(chk[nx][ny]) continue;
        dfs(nx, ny, cnt-1);
        chk[nx][ny] = false;
        if(!hasAns) q.pop();
    }
}
int main() {
    scanf("%d", &t);
    while(t--) {
        while(!q.empty()) q.pop();
        hasAns = false;
        memset(chk, false, sizeof(chk));
        scanf("%d %d %d %d %d %d",&n,&m,&sx,&sy,&ex,&ey);
        int cnt = n*m;
        if(n%2==1 && m%2==1) {
            if((sx+sy)%2!=(ex+ey)%2) {
                puts("-1");
                continue;
            }
        } else if((sx+sy)%2==(ex+ey)%2) {
            puts("-1");
            continue;
        }
        dfs(n, m, cnt);
    }
    return 0;
}
