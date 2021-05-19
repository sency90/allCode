#include <cstdio>
using namespace std;
int v[500001], cnt[500001], chk[500001], ans=0;
void dfs(int x, bool mafia) {
    if(chk[x]) return;
    chk[x] = true;

    if(mafia) ans++;

    cnt[v[x]]--;
    if(cnt[v[x]]==0 || mafia) dfs(v[x], !mafia);
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
        cnt[v[i]]++;
    }
    for(int i=1; i<=n; i++) {
        if(!chk[i] && !cnt[i]) dfs(i,true);
    }
    for(int i=1; i<=n; i++) {
        if(!chk[i]) dfs(i,false);
    }
    printf("%d", ans);
    return 0;
}
