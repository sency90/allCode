#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
int t, n, m, ex, ey;
bool chk[10][10], rchk[10][10];
char map[10][11];
int cnt[10][10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d ", &n, &m);
        for(int i=0; i<n; i++) {
            scanf("%s", map[i]);
            for(int j=0; j<m; j++) {
                if(map[i][j]=='#') {
                    rchk[i][j] = true;
                    chk[i][j] = true;
                } else {
                    rchk[i][j] = false;
                    chk[i][j] = false;
                    if(map[i][j]=='O') {
                        ex=i;
                        ey=j;
                    }
                }
            }
        }

        int nx, ny, x, y;
        queue<pair<int, int> > q;
        q.push(make_pair(ex, ey));
        cnt[ex][ey] = 0;
        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(chk[nx][ny]) continue;
                chk[nx][ny] = true;
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }

        int mx = 0;
        bool isEnd = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                chk[i][j] = rchk[i][j];
                if(cnt[i][j] >= 10) {
                    isEnd = true;
                    puts("XHAE");
                } else {
                    if(mx < cnt[i][j]) {
                        while(!q.empty()) q.pop();
                        mx = cnt[i][j];
                        q.push(make_pair(i, j));
                    } else if(mx == cnt[i][j]) {
                        q.push(make_pair(i, j));
                    }
                }
            }
            if(isEnd) break;
        }
        if(isEnd) continue;

        memset(cnt, -1, sizeof(cnt));
        int sz = q.size();
        for(int k=0; k<sz; k++) {
            cnt[q.front().first][q.front().second] = 0;
            q.push(q.front());
            q.pop();
        }

        int canMove[4];
        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            memset(canMove, 0, sizeof(canMove));
            for(int i=0; i<4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx<0) {
                    canMove[2] = 2;
                    continue;
                } else if(nx >= n) {
                    canMove[0] = 2;
                    continue;
                } else if(ny<0) {
                    canMove[3] = 2;
                    continue;
                } else if(ny>=m) {
                    canMove[1] = 2;
                    continue;
                }
                if(map[nx][ny]=='.') {
                    canMove[(i+1)%4]++;
                    canMove[((i+1)%4+2)%4]++;
                    continue;
                }
            }

            for(int i=0; i<4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                //여기서 canmove쪽으로 갈 수 있는 만큼 움직여야 한다.
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(canMove[i]<2) { // 움직일 수 있는 경우
                    while(!(nx<0||ny<0||nx>=n||ny>=m) && map[nx][ny]!='#') {
                        nx = nx+dx[i];
                        ny = ny+dy[i];
                    }
                }
                if(canMove[i]>=2) continue;
                if(map[nx][ny]=='#') continue;
                if(chk[nx][ny]) continue;

                chk[nx][ny] = true;
                if(cnt[nx][ny]==-1) cnt[nx][ny] = cnt[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
        if(cnt[ex][ey]==-1) puts("XHAE");
        else if(cnt[ex][ey]<10) puts("LUR");
        else puts("XHAE");
    }
    return 0;
}
