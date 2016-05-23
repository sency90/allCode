#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
queue<int> q;
bool v[1001][1001];
bool chk[1001];
int n;
void dfs(int x) {
    printf("%d ", x);
    chk[x] = true;
    for(int i=1; i<=n; i++) {
        if(!v[x][i]) continue;
        if(chk[i]) continue;
        dfs(i);
    }
}
int main() {
    int m, start, s, e, x;
    scanf("%d%d%d",&n,&m,&start);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&s,&e);
        v[s][e] = true;
        v[e][s] = true;
    }
    dfs(start);
    puts("");

    memset(chk, false, sizeof(chk));
    q.push(start);
    chk[start] = true;
    while(!q.empty()) {
        x = q.front(); q.pop();
        printf("%d ", x);
        for(int i=1; i<=n; i++) {
            if(!v[x][i]) continue;
            if(chk[i]) continue;
            chk[i] = true;
            q.push(i);
        }
    }
    return 0;
}
