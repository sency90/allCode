#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
vector<int> v[2001];
bool chk[2001], hasAns = false;
void dfs(int x, int depth) {
    if(hasAns) return;
    chk[x] = true;
    if(depth>=5) {
        hasAns = true;
        return;
    }
    
    for(int i=0; i<v[x].size(); i++) {
        if(chk[v[x][i]]) continue;
        chk[v[x][i]] = true;
        dfs(v[x][i], depth+1);
        chk[v[x][i]] = false;
    }
}
int main() {
    int n, m, s, e;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&s,&e);
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for(int i=0; i<n; i++) {
        memset(chk, false, sizeof(chk));
        dfs(i,1);
        if(hasAns) {
            puts("1");
            return 0;
        }
    }
    puts("0");
    return 0;
}
