#include <stdio.h>
int v[12][12],com,start,mn=0x3f3f3f3f,n;
inline int min(int x,int y) { return x<y?x:y; }
void dfs(int x,int bit,int dis) {
    bit|=(1<<x);
    if(bit==com) {
        if(v[x][start]==0) return;
        mn = min(mn,dis+v[x][start]);
        return;
    }
    for(int i=0; i<n; i++) {
        if(((bit>>i)&1)||(i==x)||v[x][i]==0) continue;
        dfs(i,bit|(1<<i),dis+v[x][i]);
    }
}
int main() {
    int z=-1;
    scanf("%d",&n);
    com = (1<<n)-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&v[i][j]);
            if(v[i][j]!=0) z=i;
        }
    }
    if(z<0) puts("-1");
    else {
        start=z;
        dfs(z,0,0);
    }
    if(mn==0x3f3f3f3f) puts("0");
    else printf("%d",mn);
    return 0;
}
