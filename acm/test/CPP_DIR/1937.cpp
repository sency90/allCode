#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int v[500][500];
int d[500][500];
bool chk[500][500];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
int realmax = 0;
int dfs(int x, int y) {
    if(d[x][y]) return d[x][y];
    chk[x][y] = true;

    int nx, ny, tmp[4]={1,1,1,1};
    bool isIn = false;
    for(int i=0; i<4; i++) {
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        if(chk[nx][ny]) tmp[i] = d[nx][ny];
        if(v[x][y] > v[nx][ny]) {
            tmp[i] = dfs(nx, ny)+1;
            isIn = true;
        }
    }
    sort(tmp, tmp+4);
    if(realmax < tmp[3]) realmax = tmp[3];
    if(d[x][y] > tmp[3]) return d[x][y];
    else return d[x][y] = tmp[3];
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    memset(chk, false, sizeof(chk));
    memset(d, 0, sizeof(d));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(chk[i][j]) continue;
            dfs(i, j);
        }
    }
    printf("%d", realmax);
    return 0;
}
