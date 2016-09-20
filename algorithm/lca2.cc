#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[100001];
int p[100001][17], d[100001];
bool chk[100001];
void dfs(int x) {
    chk[x] = true;
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(chk[y]) continue;
        p[y][0] = x;
        d[y]=d[x]+1;
        for(int j=1; (1<<j)<=d[y]; j++) {
            p[y][j] = p[p[y][j-1]][j-1];
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
        if(p[x][i]!=p[y][i]) x=p[x][i], y=p[y][i];
    }
    if(x==y) return x;
    else return p[x][0];
}
int main() {
    int n,a,b;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++) {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int m; scanf("%d", &m);
    while(m--) {
        scanf("%d%d",&a,&b);
        printf("%d\n", lca2(a,b));
    }
    return 0;
}
