#include <stdio.h>
bool chk[101];
int n;
int dfs(int x) {
    if(x>n) return 1;
    int res=0;

    chk[x] = true;
    res += dfs(x+1);
    for(int i=1; i<=n; i++) {
        if(chk[i]) printf("1 ");
        else printf("0 ");
    } puts("");


    chk[x] = false;
    res += dfs(x+1);
    for(int i=1; i<=n; i++) {
        if(chk[i]) printf("1 ");
        else printf("0 ");
    } puts("");


    return res;
}
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        printf("%d ", i);
    } puts("");
    printf("%d", dfs(1));
    return 0;
}
