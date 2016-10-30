#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[200001], tmp;
int c[200001],cnt[200001],total,mxc;
bool chk[200001];
void dfs(int x) {
    chk[x]=true;
    tmp.push_back(x);
    cnt[c[x]]++; total++;
    if(mxc!=c[x] && cnt[mxc]<cnt[c[x]]) mxc=c[x];
    for(int y:v[x]) {
        if(chk[y]) continue;
        dfs(y);
    }
}
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++) {
        scanf("%d",&c[i]);
    }
    for(int i=0; i<m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans=0;
    for(int i=1; i<=n; i++) {
        if(!chk[i]) {
            tmp.clear();
            mxc=total=0;
            dfs(i);
            ans+=total-cnt[mxc];
            for(int p: tmp) cnt[c[p]]=0;
        }
    }
    printf("%d", ans);
    return 0;
}
