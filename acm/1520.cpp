#include <stdio.h>
#include <cstring>
using namespace std;
int d[501][501];
int v[501][501];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n, m;
int f(int x, int y) {
    if(x==1 && y==1) return 1;
    if(d[x][y]) return d[x][y];
    int nx, ny;
    for(int i=0; i<4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx<1 || ny<1 || nx>n || ny>m) continue;
        if(v[nx][ny] > v[x][y]) d[x][y] += f(nx, ny);
    }
    return d[x][y];
}
int main() {
    memset(d, 0, sizeof(d));
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    printf("%d", f(n,m));
    return 0;
}
