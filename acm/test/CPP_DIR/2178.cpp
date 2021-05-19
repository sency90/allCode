#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
queue<pair<int, int> > q;
int maze[101][101];
bool chk[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;
void bfs(int x, int y) {
    if(x==n && y==m) return;
    if(!chk[x][y]) chk[x][y] = true;
    int nx, ny;
    for(int i=0; i<4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx<1 || nx>n || ny<1 || ny>m) continue;
        if(chk[nx][ny]) continue;
        if(maze[nx][ny] == 0) continue;
        chk[nx][ny] = true;
        maze[nx][ny] += maze[x][y];
        q.push(make_pair(nx, ny));
    }

    pair<int, int> t;
    while(!q.empty()) {
        t = q.front(); q.pop();
        bfs(t.first, t.second);
    }
}
int main() {
    memset(chk, false, sizeof(chk));
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs(1, 1);
    printf("%d", maze[n][m]);

    return 0;
}
