#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
int v[10001], d[10001][2];
vector<int> w[10001], ans;
bool chk[10001];
void dfs(int x) {
    chk[x] = true;
    int t;
    for(int i=0; i<w[x].size(); i++) {
        t = w[x][i];
        if(chk[t]) continue;
        dfs(t);
        d[x][0] += max(d[t][0], d[t][1]);
        d[x][1] += d[t][0];
    }
    d[x][1] += v[x];
}
void dfs(int x, int px, bool picked) {
    int t;
    if(picked) {
        ans.push_back(x);
        for(int i=0; i< w[x].size(); i++) {
            t = w[x][i];
            if(px == t) continue;
            dfs(t, x, false);
        }
        return;
    } else {
        for(int i=0; i<w[x].size(); i++) {
            t = w[x][i];
            if(px == t) continue;
            if(d[t][0] > d[t][1]) {
                dfs(t, x, false);
            } else {
                dfs(t, x, true);
            }
        }
    }
}
int main() {
    memset(d, 0, sizeof(d));
    memset(chk, false, sizeof(chk));
    int n, x, y;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i=0; i<n-1; i++) {
        scanf("%d %d", &x, &y);
        w[x].push_back(y);
        w[y].push_back(x);
    }
    dfs(1);
    int t;
    if(d[1][0]>d[1][1]) t=0;
    else t=1;
    printf("%d\n", d[1][t]);
    dfs(1, 0, t);
    for(int i=0; i<ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
