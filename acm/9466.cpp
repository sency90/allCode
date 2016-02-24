#include <stdio.h>
#include <string.h>
int v[100001], chkCnt[100001], gnum[100001], cnt;
int dfs(int x, int prevCnt, int gn) {
    chkCnt[x] = prevCnt+1;
    gnum[x] = gn;
    if(v[x] == x) return prevCnt;
    if(chkCnt[v[x]]) {
        if(gnum[v[x]] == gn) return chkCnt[v[x]]-1;
        else return chkCnt[x];
    }
    return dfs(v[x], chkCnt[x], gn);
}
int main() {
    int T, n=0, d;
    scanf("%d", &T);
    while(T--) {
        cnt = 0;
        memset(v, 0, sizeof(v));
        memset(chkCnt, 0, sizeof(chkCnt));
        memset(gnum, 0, sizeof(gnum));

        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &v[i]);
        for(int i=1; i<=n; i++) {
            if(gnum[i]==0 && chkCnt[i]==0) cnt += dfs(i,0,i);
        }
        printf("%d\n", cnt);
    }
    return 0;
}
