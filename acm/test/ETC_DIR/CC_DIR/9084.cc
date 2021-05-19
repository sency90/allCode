#include <cstdio>
#include <vector>
using namespace std;
vector<int> coin, d;
int n, m;
int main() {
#ifdef PLZRUN
    freopen("input.txt", "r", stdin);
#endif
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        coin.clear(); coin.resize(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &coin[i]);
        }
        scanf("%d", &m);
        d.clear(); d.resize(m+1, 0);
        d[0]=1;
        for(int i=0; i<n; i++) {
            for(int j=coin[i]; j<=m; j++) {
                d[j] += d[j-coin[i]];
            }
        }
        printf("%d\n", d[m]);
    }
    return 0;
}
