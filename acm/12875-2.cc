#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define N 51
vector<vector<int> > v, g;
stack<int> s;
int ds[N], scc[N], scc_cnt[N], ds_cnt=0, sccno=0;
int dfs(int x) {
    s.push(x);
    int mnds = ds[x] = ++ds_cnt;
    for(int y: v[x]) {
        if(!ds[y]) mnds = min(mnds, dfs(y));
        else if(!scc[y]) mnds = min(mnds, ds[y]); //(x,y)가 back edge와 cross edge에 해당된다. 즉, 서브트리에서 ds값이 가장작은 vertex를 찾는 것이다. (현재 정점의 서브트리에서 가장 작은 ds값이 mnds에 담긴다)
        //(x,y)가 cross edge인데 y의 scc 번호가 결정되지 않은 경우 종만북에서 말한 특이한 예외사항이 발생한다.
        //(x,y)가 cross edge인데 y의 scc 번호가 결정된 경우, 그냥 무시하면 된다. 아무것도 아님.
    }

    //mnds에는 현재 정점을 제외한 현재 정점의 서브트리에서 발견할 수 있는 vertex의 가장 작은 ds값을 의미
    //그 값이 현재 정점의 ds값과 같다면, 지금까지 stack에 집어넣었던 모든 값들을 꺼내서 scc로 묶어준다.
    if(mnds == ds[x]) {
        sccno++;
        while(true) {
            int tmp = s.top(); s.pop();
            scc[tmp] = sccno;
            scc_cnt[sccno]++;
            if(x == tmp) break;
        }
    }
    return mnds;
}
int gmx=-1,mxi;
bool chk[51];
void dfs2(int x, int mx) {
    chk[x]=true;
    for(int y: g[x]) {
        if(chk[y]) continue;
        dfs2(y,mx+1);
    }
    if(gmx<mx) {
        gmx=mx;
        mxi=x;
    }
}
char tmp[51][51];
int main() {
    int n,d; scanf("%d%d", &n,&d);
    v.resize(n, vector<int>());
    for(int i=0; i<n; i++) {
        scanf("%s", tmp[i]);
        for(int j=0; j<n; j++) {
            if(tmp[i][j]=='Y') {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }

    dfs(0);
    for(int i=0; i<n; i++) if(!ds[i]) return 0&puts("-1");

    g.resize(sccno+1, vector<int>());
    for(int i=0; i<n; i++) {
        for(int to: v[i]) {
            g[scc[i]].push_back(scc[to]);
        }
    }
    for(int i=1; i<=sccno; i++) {
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    for(int i=1; i<=sccno; i++) {
        printf("[%d]:\n", i);
        for(int j=0; j<g[i].size(); j++) {
            printf("%d ", g[i][j]);
        }
        puts("");
    }

    dfs2(1,0);
    memset(chk,false,sizeof(chk));
    dfs2(mxi,0);
    printf("%d", gmx*d);
    return 0;
}
