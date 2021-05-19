#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <queue>
#include <tuple>
using namespace std;
queue<tuple<int, int, int>> q;
int cnt;
bool v[101][101][101];
bool chk[101][101][101];
int minx, miny, minz, maxx, maxy, maxz;
int dx[6] = {0,-1,0,0,1,0};
int dy[6] = {0,0,1,0,0,-1};
int dz[6] = {1,0,0,-1,0,0};
void bfs(int x, int y, int z) {
    if(!chk[x][y][z]) chk[x][y][z] = true;

    int nx, ny, nz;
    for(int i=0; i<6; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        nz = z + dz[i];
        if(nx<minx || nx>maxx || ny<miny || ny>maxy || nz<minz || nz>maxz) continue;
        if(!v[nx][ny][nz]) continue;
        if(chk[nx][ny][nz]) {
            cnt+=2;
            continue;
        }

        chk[nx][ny][nz] = true;
        q.push(make_tuple(nx, ny, nz));
    }
    tuple<int, int, int> coord;
    while(!q.empty()) {
        coord = q.front(); q.pop();
        bfs(get<0>(coord), get<1>(coord), get<2>(coord));
    }
}
int main() {
    int t; scanf("%d", &t);
    int x, y, z, n;
    while(t--) {
        memset(v, false, sizeof(v));
        memset(chk, false, sizeof(chk));
        cnt=0;

        minx = 9;
        miny = 9;
        minz = 9;
        maxx = 0;
        maxy = 0;
        maxz = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d %d %d", &x, &y, &z);
            v[x][y][z] = true;
            if(maxx < x) maxx = x;
            if(maxy < y) maxy = y;
            if(maxz < z) maxz = z;
            if(minx > x) minx = x;
            if(miny > y) miny = y;
            if(minz > z) minz = z;
        }

        for(int i=minx; i<=maxx; i++) {
            for(int j=miny; j<=maxy; j++) {
                for(int k=minz; k<=maxz; k++) {
                    if(chk[i][j][k]) continue;
                    if(v[i][j][k]) bfs(i, j, k);
                }
            }
        }
        printf("%d\n", n*6-cnt);
    }
    return 0;
}
