#include <stdio.h>
#include <cstring>
using namespace std;
int v[401][401], d[401][401];
int main() {
    int n, m, x, y;
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    scanf("%d %d", &n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        d[y][x] = v[y][x] = 1;
        d[x][y] = v[x][y] = -1;
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            if(i==k) continue;
            for(int j=1; j<=n; j++) {
                if(i==j || k==j) continue;
                if(d[i][j]==0 && d[i][k]==1 && v[k][j]==1) {
                    d[i][j] = d[i][k];
                } else if(d[i][j]==0 && d[i][k]==-1 && v[k][j]==-1) {
                    d[i][j] = -1;
                }
            }
        }
    }
    /*
    puts("");
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n ;j++) {
            printf("%d ", d[i][j]);
        }
        puts("");
    }
    */
    int s;
    scanf("%d", &s);
    for(int i=0; i<s; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", d[x][y]);
    }
    return 0;
}
