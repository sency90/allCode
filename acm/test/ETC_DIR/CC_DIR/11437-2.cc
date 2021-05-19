#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[50001];
pair<int,int> p[50001];
bool chk[50001];
void dfs(int x) {
    chk[x]=true;
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(chk[y]) continue;
        p[y].first = x;
        p[y].second = p[x].second+1;
        dfs(y);
    }
}
int lca(int x, int y) {
    if(x==y) return x;
    if(p[x].second>p[y].second) swap(x,y);
    while(p[x].second!=p[y].second) y=p[y].first;
    while(x!=y) x=p[x].first, y=p[y].first;
    return x;
}
int main() {
    int a,b;
    int n; scanf("%d", &n);
    for(int i=0; i<n-1; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    p[1].first=1; p[1].second=0;
    dfs(1);
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a,b));
    }
    return 0;
}
