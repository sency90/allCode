#include <stdio.h>
const long long mod=1e9+7LL;
long long d[102][101];
int main() {
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    d[0][0]=1LL;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<p; j++) {
            d[i+1][j+1]+=d[i][j]*(n-i);
            d[i+1][j+1]%=mod;
            if(j>m) {
                d[i][j+1]+=d[i][j]*(i-m);
                d[i][j+1]%=mod;
            }
        }
    }
    printf("%lld\n",d[n][p]);
    return 0;
}
