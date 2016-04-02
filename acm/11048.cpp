#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int d[1001][1001];
int v[1001][1001];
int f(int x, int y) {
    if(d[x][y] != -1) return d[x][y];
    if(x<=0 || y<=0) return d[x][y]=0;
    return d[x][y] = max(f(x-1, y), f(x, y-1)) + v[x][y];
}
int main() {
    memset(d, -1, sizeof(d));
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    printf("%d", f(n, m));
}
