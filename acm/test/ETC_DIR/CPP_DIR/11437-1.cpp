#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[50001];
queue<int> q;
int d[50001], p[50001];
bool chk[50001];
int main() {
    int n, m, x, y;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d%d", &x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    q.push(1);
    chk[1] = true;
    d[1] = 0;
    while(!q.empty()) {
        x = q.front(); q.pop();
        for(int i=0; i<v[x].size(); i++) {
            if(chk[v[x][i]]) continue;
            chk[v[x][i]] = true;
            p[v[x][i]] = x;
            d[v[x][i]] = d[x]+1;
            q.push(v[x][i]);
        }
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&x,&y);
        while(d[x]>d[y]) x=p[x];
        while(d[y]>d[x]) y=p[y];
        while(x!=y) {
            x=p[x];
            y=p[y];
        }
        printf("%d\n", x);
    }
    return 0;
}
