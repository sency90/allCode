#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int d[101][101];
int main() {
    int n,m;
    scanf("%d%d", &n,&m);
    memset(d,0x3f,sizeof(d));
    for(int i=0; i<=n; i++) {
        d[i][i]=0;
    }
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        d[x][y]=min(d[x][y],w);
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            if(k==i) continue;
            for(int j=1; j<=n; j++) {
                if(i==j||j==k) continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(d[i][j]>=inf) printf("0 ");
            else printf("%d ", d[i][j]);
        }
        puts("");
    }
    return 0;
}
