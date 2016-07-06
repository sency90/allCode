#include <stdio.h>
#include <cstdlib>
#include <cmath>
using namespace std;
int var[100001], v[100001], g[370];
int main() {
    int n, m, t, l, r, x;
    scanf("%d%d", &n,&m);
    int sq = (int)sqrt(n);
    for(int i=1; i<=n; i++) {
        var[i]=i;
    }
    for(int i=0; i<m; i++) {
        scanf("%d%d%d", &t, &l, &r);
        if(t==1) {
            scanf("%d", &x);
            for(int j=l; j<=r; j++) {
                v[j] += abs(x-var[j]);
            }
        } else {
            int s = l/sq, e = r/sq-1;
            int tmp = s*sq;
            long long ans = 0;
            for(int j=l; j<tmp; j++) {
                ans += v[j];
            }
            for(int j=s; j<=e; j++) {
                ans += g[j];
            }
            for(int j=(e+1)*sq; j<=r; j++) {
                ans += v[j];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
