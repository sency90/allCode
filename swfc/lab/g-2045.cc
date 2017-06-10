#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int v[101][101];
int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
int m,n,sy,sx,ey,ex;
bool chk[101][101];
int bfs() {
    int level=0;
    queue<pii> q;
    chk[sx][sy] = true;
    q.push(pii(sx,sy));
    while (!q.empty()) {
        int sz = q.size();
        for (int z = 0; z < sz; z++) {
            pii tmp = q.front(); q.pop();
            int x = tmp.first, y = tmp.second;
            if(x==ex && y==ey) return level;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(chk[nx][ny]) continue;
                chk[nx][ny] = true;
                if(v[nx][ny] == 0) {
                    q.push(pii(nx, ny));
                }
            }
        }
        level++;
    }
    return level;
}
int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d",&m,&n);
    scanf("%d%d%d%d",&sy,&sx,&ey,&ex);
    sy--; sx--; ey--; ex--;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d",&v[i][j]);
        }
    }
    int ans = bfs();
    printf("%d\n", ans);
    return 0;
}
