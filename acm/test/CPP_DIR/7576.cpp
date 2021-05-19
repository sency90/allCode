#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
int m, n, maxR = 0;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int v[1001][1001];
bool chk[1001][1001];
queue<pair<int, int> > iq;
void bfs(int x, int y, int r) {
    queue<pair<int, int> > q;
    int X, Y;
    if(!chk[x][y]) chk[x][y] = true;
    for(int i=0; i<4; i++) {
        X = x+dx[i];
        Y = y+dy[i];

        if(X<1 || X>n || Y<1 || Y>m) continue;
        if(chk[X][Y]) continue;
        if(v[X][Y] == -1) continue;
        else if(v[X][Y] == 0) {
            chk[X][Y] = true;
            v[X][Y] = r+1;
            iq.push(make_pair(X, Y));
            maxR = (v[X][Y]>maxR? v[X][Y]:maxR);
        } else if(v[X][Y] == r) {
            chk[X][Y] = true;
            q.push(make_pair(X, Y));
        }
    }

    pair<int, int> t;
    while(!q.empty()) {
        t = q.front(); q.pop();
        bfs(t.first, t.second, r);
    }
}
int main() {
    memset(v, 0, sizeof(v));
    memset(chk, false, sizeof(chk));
    scanf("%d %d", &m, &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &v[i][j]);
            if(v[i][j] == 1) continue;
            maxR = 1;
        }
    }
    if(maxR == 0) {
        printf("0");
        return 0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(v[i][j] <= 0 || chk[i][j]) continue;
            if(v[i][j] == 1) bfs(i, j, 1);
        }
    }

    pair<int, int> t;
    while(!iq.empty()) {
        t = iq.front(); iq.pop();
        bfs(t.first, t.second, v[t.first][t.second]);
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(v[i][j] == 0) {
                maxR = 0; //maxR-1을 출력하므로 maxR=0이 되어야 한다.
                break;
            }
        }
    }

    printf("%d", maxR-1);
    return 0;
}
