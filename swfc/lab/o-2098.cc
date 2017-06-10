#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> v[11];
bool chk[11];
int a[11];
bool dfs(int x) {
    chk[x]=true;
    bool ret=true;
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(a[y]>=a[x]) return false;
        if(chk[y]) continue;
        ret&=dfs(y);
    }
    return ret;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int n,m; scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }

    dfs(1);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+1+n);

    do{
        memset(chk,false,sizeof(chk));
        if(dfs(1)) {
            for(int i=1; i<=n; i++) printf("%d ", a[i]);
            return 0;
        }
    }while(next_permutation(a+1,a+1+n));

    return 0;
}
