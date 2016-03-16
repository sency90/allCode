#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <queue>
#include <limits.h>
#include <vector>
using namespace std;
bool vis[50][50][1<<6];
char map[50][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
struct Coord{
    int x, y, key, cnt;
    Coord(int _x, int _y, int _key, int _cnt) {
        x=_x; y=_y; key=_key; cnt=_cnt;
    }
};
queue<Coord> q;
vector<pair<int, int> > v;
int main() {
    int n, m, sx, sy;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%s", map[i]);
        for(int j=0; j<m; j++) {
            if(map[i][j]=='0') {
                sx = i; sy = j;
            } else if(map[i][j]=='1') {
                v.push_back(make_pair(i, j));
            }
        }
    }

    bool isBrk;
    memset(vis, false, sizeof(vis));
    int x, y, key, nx, ny, nkey, mn=INT_MAX/2, cnt;
    q.push(Coord(sx, sy, 0, 0));
    vis[sx][sy][0] = true;
    while(!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        key = q.front().key;
        cnt = q.front().cnt;
        q.pop();
        for(int i=0; i<4; i++) {
            isBrk = false;
            nx = x + dx[i];
            ny = y + dy[i];
            nkey = key;
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(islower(map[nx][ny])) nkey |= ( 1 << (map[nx][ny]-'a') );
            else if(isupper(map[nx][ny])) {
                if((nkey & (1 << (map[nx][ny]-'A'))) == 0) continue;
            }
            if(vis[nx][ny][nkey]) continue;
            vis[nx][ny][nkey] = true;
            if(map[nx][ny]=='#') continue;
            for(int j=0; j<v.size(); j++) {
                if((nx==v[j].first) && (ny==v[j].second)) {
                    if(mn > cnt+1) {
                        mn = cnt+1;
                        isBrk = true;
                        break;
                    }
                }
            }
            if(isBrk) continue;
            q.push(Coord(nx, ny, nkey, cnt+1));
        }
    }
    if(mn == INT_MAX/2) puts("-1");
    else printf("%d", mn);
    return 0;
}
