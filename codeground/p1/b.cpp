#include <stdio.h>
#include <cstring>
#include <algorithm>
#define RND 1000000009
using namespace std;
int d[50001][101], f[50001];
bool mine[25001];
int main() {
    int t,n,k,l,x;
    scanf("%d", &t);
    for(int z=1; z<=t; z++) {
        printf("Case #%d\n", z);

        memset(d, 0, sizeof(d));
        memset(mine, false, sizeof(mine));
        scanf("%d%d%d",&n,&k,&l);
        for(int i=1; i<=l; i++) {
            scanf("%d", &x);
            mine[x] = true;
        }

        f[0] = 1;
        d[1][1] = 1;
        for(int i=1; i<=n; i++) {
            if(mine[i]) continue;
            for(int j=1; j<=k && j<=i; j++) {
                f[i] = (f[i] + f[i-j])%RND;
            }
            for(int j=1; j<=k && j<=1; j++) {
                d[i+j][j] = (d[i+j][j] + f[i]-d[i][j])%RND;
            }
        }

        int sum = 0;
        for(int i=1; i<=n; i++) {
            sum = (sum + d[n][i])%RND;
        }
        printf("%d\n", sum);
    }

    return 0;
}
