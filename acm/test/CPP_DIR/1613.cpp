#include <stdio.h>
#include <cstring>
using namespace std;
int d[401][401];
int inf = 0x3f3f3f3f;
int main() {
    int n, m, x, y;
    memset(d, 0x3f, sizeof(d));
    scanf("%d %d", &n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        d[x][y] = 1;
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
                if(d[j][i] > d[j][k] + d[k][i]) {
                    d[j][i] = d[j][k] + d[k][i];
                }
            }
        }
    }
    int s;
    scanf("%d", &s);
    for(int i=0; i<s; i++) {
        scanf("%d %d", &x, &y);
        if(d[x][y] < inf) puts("-1");
        else if(d[y][x] < inf) puts("1");
        else puts("0");
    }
    return 0;
}
