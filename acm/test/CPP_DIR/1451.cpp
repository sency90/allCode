#include <stdio.h>
#include <string.h>
long long sum[101][101], d;
int main() {
    memset(sum, 0, sizeof(sum));
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%1lld", &d);
            sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+d;
        }
    }
    long long mx=0, t[4], s[3], tmp;
    for(int i=1; i<=n-1; i++) {
        for(int j=1; j<=m-1; j++) {
            t[0] = sum[i][j];
            t[1] = sum[i][m]-t[0];
            t[2] = sum[n][j]-t[0];
            t[3] = sum[n][m]-(t[0]+t[1]+t[2]);

            if(mx < (tmp=(t[0]+t[1])*t[2]*t[3])) mx = tmp;
            if(mx < (tmp=(t[0]+t[2])*t[1]*t[3])) mx = tmp;
            if(mx < (tmp=(t[2]+t[3])*t[1]*t[0])) mx = tmp;
            if(mx < (tmp=(t[1]+t[3])*t[2]*t[0])) mx = tmp;
        }
    }
    for(int i=1; i<=n-2; i++) {
        s[0] = sum[i][m];
        for(int j=i+1; j<=n-1; j++) {
            s[1] = sum[j][m]-s[0];
            s[2] = sum[n][m]-sum[j][m];
            if(mx < (tmp=s[0]*s[1]*s[2])) mx = tmp;
        }
    }
    for(int i=1; i<=m-2; i++) {
        s[0] = sum[n][i];
        for(int j=i+1; j<=m-1; j++) {
            s[1] = sum[n][j]-s[0];
            s[2] = sum[n][m]-sum[n][j];
            if(mx < (tmp=s[0]*s[1]*s[2])) mx = tmp;
        }
    }
    printf("%lld", mx);
    return 0;
}
