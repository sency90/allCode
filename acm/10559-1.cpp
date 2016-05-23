#include <stdio.h>
#include <string.h>
#include <queue>
#include <tuple>
using namespace std;
queue<tuple<int, int, int>> q;
int cnt;
bool v[10][10][10];
bool chk[10][10][10];
int vcnt[10][10][10];
int minx, miny, minz, maxx, maxy, maxz;
int dx[6] = {0,-1,0,0,1,0};
int dy[6] = {0,0,1,0,0,-1};
int dz[6] = {1,0,0,-1,0,0};
void fbfs(int x, int y, int z) {
    if(!chk[x][y][z]) chk[x][y][z] = true;

    int nx, ny, nz;
    for(int i=0; i<6; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        nz = z + dz[i];
        if(nx<0 || nx>=10 || ny<0 || ny>=10 || nz<0 || nz>=10) continue;
        if(!v[nx][ny][nz]) {
            vcnt[nx][ny][nz]++;
            if(vcnt[nx][ny][nz] >= 3) {
                if(!v[nx][ny][nz]) {
                    v[nx][ny][nz] = true;
                    chk[nx][ny][nz] = false;
                } else continue;
            } else continue;
        }
        if(chk[nx][ny][nz]) continue;

        chk[nx][ny][nz] = true;
        q.push(make_tuple(nx, ny, nz));
    }
    tuple<int, int, int> coord;
    while(!q.empty()) {
        coord = q.front(); q.pop();
        fbfs(get<0>(coord), get<1>(coord), get<2>(coord));
    }
}
void bfs(int x, int y, int z) {
    if(!chk[x][y][z]) chk[x][y][z] = true;

    int nx, ny, nz;
    for(int i=0; i<6; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        nz = z + dz[i];
        if(nx<0 || nx>=10 || ny<0 || ny>=10 || nz<0 || nz>=10) continue;
        if(!v[nx][ny][nz]) continue;
        if(chk[nx][ny][nz]) {
            cnt++;
            continue;
        }

        cnt++;
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
        memset(vcnt, 0, sizeof(vcnt));
        memset(chk, false, sizeof(chk));
        cnt=0;

        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d %d %d", &x, &y, &z);
            v[x][y][z] = true;
            vcnt[x][y][z] = 1;
        }
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                for(int k=0; k<10; k++) {
                    if(chk[i][j][k]) continue;
                    if(vcnt[i][j][k] == 0) fbfs(i, j, k);
                }
            }
        }

        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                for(int k=0; k<10; k++) {
                    if(chk[i][j][k]) continue;
                    if(v[i][j][k]) bfs(i, j, k);
                }
            }
        }
        printf("%d\n", n*6-cnt);
    }
    return 0;
}
