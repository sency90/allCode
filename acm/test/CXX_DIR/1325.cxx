#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
queue<int> q;
stack<int> s;
vector<int> v[10001], dag[10001], group[10001], ans2;
vector<pii> ans;

int ds[10001],g[10001],d[10001];
int dsno=0,gno=1;
bool chk[10001],indeg[10001];
int scc(int x) {
    s.push(x);
    int ret=ds[x]=++dsno;
    for(int y: v[x]) {
        if(!ds[y]) ret = min(ret, scc(y));
        else if(!g[y]) ret = min(ret, ds[y]);
    }

    if(ret==ds[x]) {
        while(true) {
            int tmp = s.top(); s.pop();
            g[tmp]=gno;
            if(tmp==x) break;
        }
        gno++;
    }
    return min(ret,ds[x]);
}
void dfs(int x) {
    chk[x]=true;
    for(int y: v[x]) {
        if(!chk[y]) dfs(y);
        if(g[x]!=g[y]) {
            dag[g[x]].push_back(g[y]);
            indeg[g[y]]=true;
        }
    }
}
int main() {
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&x,&y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++) if(!ds[i]) scc(i);
    for(int i=1; i<=n; i++) {
        if(!chk[i]) dfs(i);
        group[g[i]].push_back(i);
    }

    for(int i=1; i<gno; i++) {
        if(dag[i].size()<=1) continue;
        sort(dag[i].begin(), dag[i].end());
        dag[i].erase( unique(dag[i].begin(),dag[i].end()), dag[i].end() );
    }

    for(int k=1; k<gno; k++) {
        if(indeg[k]) continue;
        int cc=1;
        q.push(k);
        memset(chk,false,sizeof(chk));
        chk[k]=true;
        while(!q.empty()) {
            int x=q.front(); q.pop();
            cc+=group[x].size();
            for(int y: dag[x]) {
                if(chk[y]) continue;
                chk[y]=true;
                q.push(y);
            }
        }
        ans.push_back({cc,k});
    }

    sort(ans.begin(),ans.end());
    ans.erase(ans.begin(),lower_bound(ans.begin(), ans.end(), pii(ans.back().first,0)));
    for(auto &it: ans) {
        for(int j: group[it.second]) ans2.push_back(j);
    }
    sort(ans2.begin(), ans2.end());
    for(int i: ans2) printf("%d ", i);
    return 0;
}
