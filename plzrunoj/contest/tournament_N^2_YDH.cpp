#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
pii d[501][501];
int v[501];
inline int ABS(int x) { return (x<0) ? -x : x; }
const int inf = 0x3f3f3f3f;
int main() {
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            d[i][j].first = inf;
        }
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        d[i][i].first = 0;
        d[i][i].second = v[i];
    }
    for (int len=1; len<n; len++) {
        for (int i=0; i+len<n; i++) {
            d[i][i+len].second = max(d[i][i+len-1].second, d[i+len][i+len].second);
            for (int k=i; k+1<=i+len; k++) {
                d[i][i+len].first = min(d[i][i+len].first, d[i][k].first+d[k+1][i+len].first+ABS(d[i][k].second-d[k+1][i+len].second));
            }
        }
    }
    printf("%d\n", d[0][n-1].first);
    return 0;
}
