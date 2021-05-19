#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int d[10001], v[10001];
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        memset(d, 0, sizeof(d));
        int n; scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
            d[v[i]]++;
        }
        int m; scanf("%d", &m);
        //d[i][m] = d[i-1][m] + d[i-1][m-coin[i]]
        //d[v[i]...m] = d[v[i]...m] + d[(v[i]...m) - coin[i]]
        //d[0]=1;
        for(int i=v[0]; i<=m; i+=v[0]) d[i]++;
        for(int i=0; i<n; i++) {
            for(int j=m; j>=v[i]; j--) {
                d[j] += d[j-v[i]];
            }
        }
        printf("%d\n", d[m]);
        memset(d, 0, sizeof(d));
        d[0]=1;
        for(int i=0; i<n; i++) {
            for(int j=v[i]; j<=m; j++) {
                d[j] += d[j-v[i]];
            }
        }
        printf("** %d\n", d[m]);
    }
    return 0;
}
