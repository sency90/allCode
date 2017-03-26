#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> edge[200010];
int color[200010];
int moth[200010];
bool chk[200010];
int ans = 0;
void dfs(int u) {
    int cnt = 0;
    chk[u] = true;
    for(int i = 0;i<edge[u].size();i++) {
        int v = edge[u][i];
        if(chk[v]) continue;
        while(1) {
            cnt++;
            if(cnt != color[moth[u]] && cnt != color[u]) break;
        }
        color[v] = cnt;
        if(cnt > ans) ans = cnt;
        moth[v] = u;
        dfs(v);
    }
}
int main() {
    int i, n;
    int x, y;
    scanf("%d",&n);
    for(i=0;i<n-1;i++) {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    moth[1] = 0;
    color[1] = 1;
    dfs(1);
    printf("%d\n",ans);
    for(i=1;i<=n;i++) printf("%d ",color[i]);
    printf("\n");
    return 0;
}
