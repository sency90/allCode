#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int v[501][501], win[501], n;
bool chk[501];
vector<int> ans;
void dfs(int x) {
    chk[x]=true;
    for(int y=1; y<=n; y++) {
        if(!chk[y]&&v[x][y]) dfs(y);
    }
    ans.push_back(x);
}
bool check() {
    for(int i=0; i<ans.size(); i++) {
        for(int j=i+1; j<ans.size(); j++) {
            if(v[ans[j]][ans[i]]) return false;
            if(!v[ans[i]][ans[j]]) return false;
        }
    }
    return true;
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        scanf("%d",&n);
        memset(win,0,sizeof(win));
        memset(v,0,sizeof(v));
        for(int i=1; i<=n; i++) {
            scanf("%d",&win[i]);
        }
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                v[win[i]][win[j]]=1;
            }
        }

        int m,x,y;
        scanf("%d", &m);
        for(int i=0; i<m; i++) {
            scanf("%d%d",&x,&y);
            v[x][y]^=1; v[y][x]^=1;
        }
        ans.clear();
        memset(chk,false,sizeof(chk));
        for(int i=1; i<=n; i++) if(!chk[i]) dfs(i);
        reverse(ans.begin(), ans.end());

        if(check()) for(int i=0; i<ans.size(); i++) printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
        else puts("IMPOSSIBLE");
    }
    return 0;
}
