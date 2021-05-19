#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int> > v[100001];
bool chk[100001];
queue<int> q;
int d[100001];
void bfs(int x) {
    if(!chk[x]) chk[x] = true;
    for(int i=0; i<v[x].size(); i++) {
        if(chk[v[x][i].first]) continue;
        chk[v[x][i].first] = true;
        d[v[x][i].first] = d[x] + v[x][i].second;
        q.push(v[x][i].first);
    }
    int t;
    while(!q.empty()) {
        t = q.front(); q.pop();
        bfs(t);
    }
}
int main() {
    int n, x, y, w; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        for(scanf("%d",&y); y!=-1; scanf("%d",&y)) {
            scanf("%d", &w);
            v[x].push_back(make_pair(y, w));
        }
    }

    memset(chk, false, sizeof(chk));
    memset(d, 0, sizeof(d));
    bfs(1);
    int s = 1;
    for(int i=2; i<=n; i++) {
        if(d[s] < d[i]) s = i;
    }

    memset(chk, false, sizeof(chk));
    memset(d, 0, sizeof(d));
    bfs(s);
    for(int i=1; i<=n; i++) {
        if(d[s] < d[i]) s = i;
    }
    printf("%d", d[s]);
    return 0;
}
