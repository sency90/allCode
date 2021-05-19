#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v[101];
int ans[101],n,m;
bool mid[101],chk[101];
int dfs(int x) {
    if(x==n) return 1;
    int ret=0;
    for(auto &y: v[x]) ret+=dfs(y.first)*y.second;
    return ret;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        mid[x]=true;
        v[y].push_back({x,k});
    }
    for(int i=1; i<=n; i++) {
        if(mid[i]) continue;
        ans[i]=dfs(i);
    }
    for(int i=1; i<=n; i++) {
        if(mid[i]) continue;
        printf("%d %d\n",i,ans[i]);
    }
    return 0;
}
