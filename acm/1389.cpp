#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[101];
queue<int> q;
int chk[101], sz, mn=100000000;
bool bfs(int x) {
    memset(chk, false, sizeof(chk));
    int cnt=0, sum=0;
    q.push(x);
    chk[x]=true;
    while(!q.empty()) {
        sz = q.size();
        for(int r=0; r<sz; r++) {
            x = q.front(); q.pop();
            for(int i=0; i<v[x].size(); i++) {
                if(chk[v[x][i]]) continue;
                chk[v[x][i]] = true;
                q.push(v[x][i]);
                sum += cnt+1;
            }
        }
        cnt++;
    }
    if(mn > sum) {
        mn = sum;
        return true;
    }
    return false;
}
int main() {
    int n, m, x, y, ans;
    scanf("%d %d", &n,&m);
    memset(v, 0, sizeof(v));
    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++) {
        if(bfs(i)) ans = i;
    }
    printf("%d", ans);
    return 0;
}
