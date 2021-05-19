#include <stdio.h>
#include <queue>
#include <string.h>
#include <limits.h>
using namespace std;
int m;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int v[101][101];
bool chk[101][101];
int g[101][101];
queue<pair<int, int> > iq;
int mini = INT_MAX;
void bfs(int x, int y, int gn) {
    if(g[x][y] == 0) g[x][y] = gn;
    queue<pair<int, int> > q;
    int X, Y;
    if(!chk[x][y]) chk[x][y] = true;
    for(int i=0; i<4; i++) {
        X = x+dx[i];
        Y = y+dy[i];

        if(X<1 || X>m || Y<1 || Y>m) continue;
        if(chk[X][Y]) {
            if(v[X][Y]==0 || v[x][y]==0) continue;
            if(g[x][y] == g[X][Y] || g[X][Y]==0) continue;
            if(mini > v[x][y]+v[X][Y]) mini = v[x][y] + v[X][Y];
            //continue;
        } else if(v[X][Y] == 0) {
            chk[X][Y] = true;
            v[X][Y] = v[x][y]+1;
            if(g[X][Y] == 0) g[X][Y] = g[x][y];
            iq.push(make_pair(X, Y));
        } else if(v[X][Y] == v[x][y]) {
            chk[X][Y] = true;
            q.push(make_pair(X, Y));
        }
    }

    pair<int, int> t;
    while(!q.empty()) {
        t = q.front(); q.pop();
        bfs(t.first, t.second, g[x][y]);
    }
}
int main() {
    memset(v, 0, sizeof(v));
    memset(chk, false, sizeof(chk));
    memset(g, 0, sizeof(g));
    scanf("%d", &m);
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &v[i][j]);
            if(v[i][j] == 1) continue;
        }
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=m; j++) {
            if(v[i][j] == 0 || chk[i][j]) continue;
            if(v[i][j] == 1) bfs(i, j, i*100+j);
        }
    }

    pair<int, int> t;
    while(!iq.empty()) {
        t = iq.front(); iq.pop();
        bfs(t.first, t.second, g[t.first][t.second]);
    }

    printf("%d", mini-2);
    return 0;
}
