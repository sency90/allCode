#include <stdio.h>
const int inf = 0x3f3f3f3f;
int v[13][13],n,mn=inf;
bool chk[13];
inline int min(int x, int y) { return x<y?x:y; }
void dfs(int level, int x, int dist) {
    if(level == n-1) {
        if(v[x][0]==0) return;
        mn = min(mn, dist+v[x][0]);
        return;
    }
    chk[x]=true;
    for(int i=0; i<n; i++) {
        if(chk[i]||v[x][i]==0) continue;
        dfs(level+1, i, dist+v[x][i]);
    }
    chk[x]=false;
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    dfs(0,0,0);
    if(mn==inf) puts("0");
    else printf("%d",mn);
    return 0;
}
