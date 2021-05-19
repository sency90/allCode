#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[100001];
int ans[100001], am[100001];
void dfs(int x, int sum) {
    for(int y: v[x]) {
        ans[y]+=sum+am[y];
        dfs(y,sum+am[y]);
    }
}
int main() {
    int n,m; scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        int x; scanf("%d", &x);
        if(x!=-1) v[x].push_back(i);
    }
    int x,galgum;
    for(int i=0; i<m; i++) {
        scanf("%d%d",&x,&galgum);
        am[x]+=galgum;
    }
    dfs(1,0);
    for(int i=1; i<=n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
