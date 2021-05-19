#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[10002];
queue<int> q;
int tm[10002], cnt[10002], d[10002];
int main() {
    int n, m, y;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d %d", &tm[i], &m);
        for(int j=0; j<m; j++) {
            scanf("%d", &y);
            v[i].push_back(y);
            cnt[i]++;
        }
    }
    for(int i=1; i<=n; i++) {
        if(cnt[i]==0) {
            q.push(i);
            d[i] = tm[i];
        }
    }

    int x;
    while(!q.empty()) {
        int tmp = q.front(); q.pop();
        for(int i=0; i<v[tmp].size(); i++) {
            x = v[tmp][i];
            cnt[x]--;
            if(d[x] < d[tmp]+tm[x]) {
                d[x] = d[tmp] + tm[x];
            }
            if(cnt[y] == 0) {
                q.push(v[tmp][i]);
            }
        }
    }
    int mx;
    for(int i=1; i<=n; i++) {
        if(mx < d[i]) mx=d[i];
    }
    printf("%d", mx);
    return 0;
}
