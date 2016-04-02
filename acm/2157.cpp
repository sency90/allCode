#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
int cost[301][301];
int d[301][301];
int main() {
    memset(d, -1, sizeof(d));
    memset(cost, -1, sizeof(cost));
    int n, m, k, s, e, w, ans=0;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<k; i++) {
        scanf("%d%d%d", &s, &e, &w);
        if(s<e) {
            if(cost[s][e] < w) {
                cost[s][e] = w;
            }
        }
    }
    d[1][1] = 0;
    for(int i=2; i<=n; i++) {
        for(int j=1; j<i; j++) {
            if(cost[j][i] == -1) continue;
            for(int k=2; k<=m; k++) {
                if(d[j][k-1] == -1) continue;
                if(d[i][k] < d[j][k-1] + cost[j][i]) {
                    d[i][k] = d[j][k-1] + cost[j][i];
                }
            }
        }
    }
    for(int i=1; i<=m; i++) {
        if(ans < d[n][i]) ans=d[n][i];
    }
    printf("%d", ans);
    return 0;
}
