#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
bool chk[301][301];
int l, cnt, memCnt, xe, ye, nx, ny;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int main() {
    int t,x,y,sz;
    bool isBrk;
    scanf("%d", &t);
    while(t--) {
        cnt = 0;
        memset(chk, false, sizeof(chk));
        chk[x][y] = true;
        isBrk = false;
        scanf("%d %d %d %d %d", &l, &x, &y, &xe, &ye);
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        while(!q.empty()) {
            sz = q.size();
            for(int j=0; j<sz; j++) {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                if(x == xe && y == ye) {
                    //printf("%d\n", cnt);
                    isBrk = true;
                    break;
                }
                for(int i=0; i<8; i++) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if(nx<0 || nx>=l || ny<0 || ny>=l) continue;
                    if(chk[nx][ny]) continue;
                    chk[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
            if(isBrk) break;
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
