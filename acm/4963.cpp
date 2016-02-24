#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
queue<pair<int, int> > q;
int v[51][51], w, h;
bool chk[51][51];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
void bfs(int x, int y) {
    int X, Y;
    if(!chk[x][y]) chk[x][y] = true;
    for(int i=0; i<8; i++) {
        X = x+dx[i];
        Y = y+dy[i];
        if(X < 1 || X > h || Y < 1 || Y > w) continue;
        if(chk[X][Y]) continue;
        if(v[X][Y] == 0) continue;
        chk[X][Y] = true;
        q.push(make_pair(X, Y));
    }
    pair<int, int> t;
    while(!q.empty()) {
        t = q.front();
        q.pop();
        bfs(t.first, t.second);
    }
}
int main() {
    while(true) {
        memset(v, 0, sizeof(v));
        memset(chk, false, sizeof(chk));
        scanf("%d %d", &w, &h);
        if(w==0 && h==0) return 0;
        for(int i=1; i<=h; i++) {
            for(int j=1; j<=w; j++) {
                scanf("%1d", &v[i][j]);
            }
        }

        int totalCnt = 0;
        for(int i=1; i<=h; i++) {
            for(int j=1; j<=w; j++) {
                if((!chk[i][j]) && v[i][j]) {
                    totalCnt++;
                    bfs(i,j);
                }
            }
        }
        printf("%d\n", totalCnt);
    }
}
