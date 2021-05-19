#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<int> v[501];
queue<int> q;
int tm[501], d[501], cnt[501];
int main() {
    int n, x, tmp;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &tm[i]);
        while(true) {
            scanf("%d", &x);
            if(x==-1) break;
            v[x].push_back(i);
            cnt[i]++;
        }
    }
    for(int i=1; i<=n; i++) {
        if(cnt[i]==0) {
            v[0].push_back(i);
            cnt[i]++;
        }
    }
    memset(d, 0, sizeof(d));
    q.push(0);
    while(!q.empty()) {
        tmp = q.front(); q.pop();
        for(int i=0; i<v[tmp].size(); i++) {
            cnt[v[tmp][i]]--;
            if(d[v[tmp][i]] < d[tmp]+tm[v[tmp][i]]) d[v[tmp][i]] = d[tmp] + tm[v[tmp][i]];
            if(cnt[v[tmp][i]]==0) {
                q.push(v[tmp][i]);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        printf("%d\n", d[i]);
    }
    return 0;
}
