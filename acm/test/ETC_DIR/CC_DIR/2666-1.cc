#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int v[21], d[21][21][21];
int main() {
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", &v[i]);
    memset(d,0x3f,sizeof(d));
    if(l>r) swap(l,r);
    d[0][l][r]=0;
    for(int i=0; i<m; i++) {
        for(int l=1; l<=n; l++) {
            for(int r=l+1; r<=n; r++) {
                d[i+1][v[i]][r]=min(d[i+1][v[i]][r],d[i][l][r]+abs(v[i]-l));
                d[i+1][l][v[i]]=min(d[i+1][l][v[i]],d[i][l][r]+abs(v[i]-r));
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            ans=min(ans,d[m][i][j]);
        }
    }
    printf("%d", ans);
    return 0;
}
