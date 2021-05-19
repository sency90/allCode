#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
struct Coord{
    int c, x, y;
    Coord(int _c, int _x, int _y) {
        c=_c; x=_x; y=_y;
    }
    bool operator<(const Coord &rhs) const {
        if(c==rhs.c) {
            if(x==rhs.x) {
                return y > rhs.y;
            } else return x > rhs.x;
        } else return c > rhs.c;
    }
};
int v[100][100];
int cnt[100][100];
priority_queue<Coord> mnh;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
    int n, m; scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &v[i][j]);
        }
    }
    int nx, ny, x, y;
    memset(cnt, -1, sizeof(cnt));
    mnh.push(Coord(0,0,0));
    cnt[0][0] = 0;
    while(!mnh.empty()) {
        x = mnh.top().x;
        y = mnh.top().y;
        mnh.pop();
        for(int i=0; i<4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(cnt[nx][ny]!=-1) continue;
            if(v[nx][ny]==1) {
                cnt[nx][ny] = cnt[x][y]+1;
            } else {
                cnt[nx][ny] = cnt[x][y];
            }
            mnh.push(Coord(cnt[nx][ny], nx, ny));
        }
    }
    printf("%d", cnt[n-1][m-1]);
    return 0;
}
