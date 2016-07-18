#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
vector<int> v[1002];
int r[1001][1001], src, sink;
bool chk[1001];
int dfs(int x, int f) {
    if(chk[x]) return 0;
    chk[x] = true;
    if(x==sink) return f;

    for(int i=0; i<v[x].size(); i++) {
        if(r[x][v[x][i]] <= 0) continue;
        int flow = dfs(v[x][i], min(f,r[x][v[x][i]]));
        if(flow) {
            r[x][v[x][i]] -= flow;
            r[v[x][i]][x] += flow;
            return flow;
        }
    }
    return 0;
}
int main() {
    int n,m,d,t;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        v[0].push_back(i);
        v[i].push_back(n+1);
        scanf("%d", &d);
        for(int j=0; j<d; j++) {
            scanf("%d", &t);
            v[i].push_back(t);
            r[i][t]=r[t][i]=1;
        }
    }

    src=0, sink=n+1;
    int ans = 0;
    while(true) {
        memset(chk,false,sizeof(chk));
        int f = dfs(src, 0x3f3f3f3f);
        if(f == 0) break;
        ans += f;
    }
    printf("%d\n", ans);
    return 0;
}
