#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
int d[1001][1001], mx=0;
bool chk[1001][1001];
int f(int x, int y) {
    if(chk[x][y]) return d[x][y];
    chk[x][y] = true;
    if(x==0 || y==0) return d[x][y]=0;
    int l = f(x-1, y), u = f(x, y-1), z;
    if(l < u) u=l;
    if(mx < d[x][y]) mx = d[x][y];
    if(d[x][y]==0) return d[x][y];
    if((z=sqrt(u))==0) return d[x][y];
    else if(d[x-z][y-z] > 0) d[x][y] = u*2-(z-1)*(z-1)+2;
    else d[x][y] = u;
    if(mx < d[x][y]) mx = d[x][y];
    return d[x][y];
}
int main() {
    int n, m;
    memset(chk, false, sizeof(chk));
    memset(d, 0, sizeof(d));
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%1d", &d[i][j]);
        }
    }
    f(n, m);
    printf("%d", mx);
    return 0;
}
