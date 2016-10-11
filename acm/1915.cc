#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int v[1001][1001], d[1001][1001];
int f(int x, int y) {
    if(x==0||y==0) return 0;
    int &ret = d[x][y];
    if(ret!=-1) return ret;
    else ret=0;
    if(v[x][y]) {
        ret = min({f(x-1,y),f(x,y-1),f(x-1,y-1)})+1;
    } else {
        f(x-1,y); f(x,y-1); f(x-1,y-1);
        ret=0;
    }
    return ret;
}
int main() {
    int n,m;
    memset(d, -1, sizeof(d));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%1d",&v[i][j]);
        }
    }
    f(n,m);
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1; j<=m; j++) {
            ans=max(ans,d[i][j]);
        }
    }
    printf("%d", ans*ans);
    return 0;
}
