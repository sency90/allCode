#include <stdio.h>
int v[1025][1025];
int main() {
    register int n,m,i,j,a,b,c,d;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            scanf("%d", &v[i][j]);
            v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
        }
    }
    for(i=0; i<m; i++) {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a--;b--;
        printf("%d\n",v[c][d]-v[c][b]-v[a][d]+v[a][b]);
    }
    return 0;
}
