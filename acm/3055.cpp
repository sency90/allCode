#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
char map[51][51];
int wno[51][51];
int cnt[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool chk[51][51];
queue<pair<int, int> > wq;
queue<pair<int, int> > q;
int main() {
    int r, c, ex, ey;
    scanf("%d%d ", &r, &c);
    memset(wno, 0, sizeof(wno));
    memset(cnt, 0, sizeof(cnt));
    memset(map, 0, sizeof(map));
    bool hasWater = false;
    for(int i=0; i<r; i++) {
        scanf("%s", map[i]);
        for(int j=0; j<c; j++) {
            if(map[i][j]=='*') {
                hasWater = true;
                wno[i][j] = 1;
                wq.push(make_pair(i, j));
            } else {
                if(map[i][j]=='S') {
                    q.push(make_pair(i, j));
                    cnt[i][j] = 1;
                } else if(map[i][j]=='D') {
                    ex=i;
                    ey=j;
                } else if(map[i][j]=='X') {
                    wno[i][j]=-1;
                }
            }
        }
    }
    int x, y, nx, ny;
    if(hasWater) {
        memset(chk, false, sizeof(chk));
        while(!wq.empty()) {
            x = wq.front().first;
            y = wq.front().second;
            wq.pop();
            for(int i=0; i<4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
                if(chk[nx][ny]) continue;
                if(wno[nx][ny]!=0) continue;
                chk[nx][ny] = true;
                if(wno[nx][ny]==-1) continue;
                if(map[nx][ny]=='D') {
                    wno[nx][ny] = INT_MAX/2;
                    continue;
                }
                wno[nx][ny] = wno[x][y]+1;
                wq.push(make_pair(nx, ny));
            }
        }
    }
    memset(chk, false, sizeof(chk));
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
            if(chk[nx][ny]) continue;
            if(cnt[nx][ny]!=0) continue;
            chk[nx][ny] = true;
            if(wno[nx][ny] > cnt[x][y]+1 || wno[nx][ny]==0) {
                cnt[nx][ny] = cnt[x][y]+1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    if(cnt[ex][ey]==0) puts("KAKTUS");
    else printf("%d", cnt[ex][ey]-1);
}
