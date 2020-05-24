#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[101];
bool chk[101];
int ans=0;
void dfs(int x) {
    ans++;
    chk[x] = true;
    for(int y: v[x]) {
        if(chk[y]) continue;
        dfs(y);
    }
}
int main() {
    int n,m; scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y; scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    printf("%d", ans-1);
    return 0;
}
