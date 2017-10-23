#include <stdio.h>
bool chk[11];
int n,v[11];
void dfs(int x){
    if(x==n) {
        for(int i=0; i<n; i++) printf("%d ", v[i]);
        puts("");
        return ;
    }
    for(int i=1; i<=n; i++) {
        if(chk[i]) continue;
        chk[i]=true;
        v[x]=i;
        dfs(x+1);
        chk[i]=false;
    }
}
int main() {
    scanf("%d",&n);
    dfs(0);
    return 0;
}
