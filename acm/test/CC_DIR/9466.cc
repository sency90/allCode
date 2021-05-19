#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cnt[100001], v[100001], gnum[100001];
int dfs(int x, int pcnt, int g) {
    cnt[x] = pcnt+1;
    gnum[x] = g;
    if(cnt[v[x]]) {
        if(gnum[v[x]] == g) return cnt[v[x]]-1;
        else return cnt[x];
    }
    return dfs(v[x], cnt[x], g);
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n; scanf("%d", &n);
        memset(v, 0, sizeof(v));
        memset(cnt, 0, sizeof(cnt));
        memset(gnum, 0, sizeof(gnum));

        for(int i=1; i<=n; i++) scanf("%d", &v[i]);

        int ans=0;
        for(int i=1; i<=n; i++) {
            if(!gnum[i] && !cnt[i]) ans += dfs(i,0,i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
