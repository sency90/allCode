#include <stdio.h>
int v[20][20];
int main() {
    for(int i=1; i<20; i++) {
        for(int j=1; j<20; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        for(int u=1; u<20; u++) {
            v[u][y]^=1;
            v[x][u]^=1;
        }
    }
    for(int i=1; i<20; i++) {
        for(int j=1; j<20; j++) {
            printf("%d ", v[i][j]);
        }
        puts("");
    }
    return 0;
}
