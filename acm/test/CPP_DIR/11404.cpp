#include <stdio.h>
#define INF 1000000001
int d[101][101];
int main() {
    int n, m, s, e, w;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) d[i][j]=0;
            else d[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &s,&e,&w);
        if(d[s][e] > w) d[s][e] = w;
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(d[i][j] > d[i][k]+d[k][j]) {
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(d[i][j]>=INF) printf("0 ");
            else printf("%d ", d[i][j]);
        }
        puts("");
    }
    return 0;
}
