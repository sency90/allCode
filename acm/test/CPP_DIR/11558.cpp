#include <stdio.h>
#include <cstring>
using namespace std;
bool chk[10001];
int n, t, mn, v[10001];
void dfs(int x, int cnt) {
    chk[x] = true;
    if(x==n) {
        mn = cnt;
        return;
    }
    if(chk[v[x]]) return;
    dfs(v[x], cnt+1);
}
int main() {
    scanf("%d",&t);
    while(t--) {
        memset(v, 0, sizeof(v));
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &v[i]);
        }
        memset(chk, false, sizeof(chk));
        mn=0;
        dfs(1, 0);
        printf("%d\n", mn);
    }
    return 0;
}
