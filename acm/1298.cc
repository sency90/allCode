#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[101];
int ym[101], xm[101];
bool chk[101];
bool bipartite(int x) {
    if(chk[x]) return false;
    chk[x]=true;
    for(auto &y: v[x]) {
        if(!ym[y]||bipartite(ym[y])) {
            ym[y]=x;
            xm[x]=y;
            return true;
        }
    }
    return false;
}
int main() {
    int n,m; scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int a,b; scanf("%d%d",&a,&b);
        v[a].push_back(b);
    }
    int ans=0;
    for(int i=1; i<=n; i++) {
        memset(chk, false, sizeof(chk));
        if(bipartite(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
