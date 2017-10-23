#include <stdio.h>
const int inf = 0x3f3f3f3f;
int v[12][12],n,com;
int mn=inf,start;
inline int min(int x, int y) { return x<y?x:y; }
void dfs(int x, int bit, int dist) {
    bit|=(1<<x);
    if(bit == com) {
        if(v[x][start]==0) return;
        mn = min(mn, dist+v[x][start]);
        return;
    }
    for(int i=0; i<n; i++) {
        if((bit>>i) & 1) continue;
        if(v[x][i]==0) continue;
        dfs(i, bit, dist+v[x][i]);
    }
}
int main() {
    scanf("%d",&n);
    com = (1<<n)-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&v[i][j]);
            if(v[i][j]!=0) start=i;
        }
    }
    dfs(start,0,0);
    if(mn==inf) puts("0");
    else printf("%d", mn);
    return 0;
}
