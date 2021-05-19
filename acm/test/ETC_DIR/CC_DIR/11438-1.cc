#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100001];
bool chk[100001];
int p[100001][17], d[100001];
void dfs(int x) {
    chk[x] = true;
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(chk[y]) continue;
        d[y] = d[x]+1;
        p[y][0] = x;
        for(int j=1; (1<<j)<=d[y]; j++) {
            p[y][j] = p[ p[y][j-1] ][j-1];
        }
        dfs(y);
    }
}
int lca2(int x, int y) {
    if(x==y) return x;
    if(d[x]>d[y]) swap(x,y);
    for(int i=16; i>=0; i--) {
        if((1<<i) <= d[y]-d[x]) y=p[y][i];
    }
    if(x==y) return x;
    for(int i=16; i>=0; i--) {
        if(p[x][i]!=p[y][i]) {
            x=p[x][i];
            y=p[y][i];
        }
    }
    if(x==y) return x;
    else return p[x][0];
}
int main() {
    int n,a,b;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    d[1]=0; p[1][0]=0;
    dfs(1);
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&a,&b);
        printf("%d\n", lca2(a,b));
    }
    return 0;
}
