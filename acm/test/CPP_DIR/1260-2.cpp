#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<int> q;
vector<int> v[1001];
bool chk[1001];
int n;
void dfs(int x) {
    chk[x] = true;
    printf("%d ", x);
    for(int i=0; i<v[x].size(); i++) {
        if(chk[v[x][i]]) continue;
        dfs(v[x][i]);
    }
}
int main() {
    int m, start, s, e;
    scanf("%d%d%d",&n,&m,&start);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&s,&e);
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for(int i=1; i<=n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    dfs(start);
    puts("");

    int x;
    memset(chk, false, sizeof(chk));
    q.push(start);
    chk[start] = true;
    while(!q.empty()) {
        x = q.front(); q.pop();
        printf("%d ", x);
        for(int i=0; i<v[x].size(); i++) {
            if(chk[v[x][i]]) continue;
            chk[v[x][i]] = true;
            q.push(v[x][i]);
        }
    }
    return 0;
}
