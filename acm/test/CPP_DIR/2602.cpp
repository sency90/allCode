#include <stdio.h>
#include <string.h>
char g[21], v[2][101];
int dp[2][101][21];
//dp[p][n][i]는 g[0...i]까지의 문자열이 v[p][0..n]에 몇개 들어있는지 나타낸다.
int vlen, glen;
int f(int p, int n, int i) {
    if(dp[p][n][i]!=-1) return dp[p][n][i];
    if(n < i) return dp[p][n][i] = 0;
    if(i==0) {
        if(n==0) {
            if(v[p][n]==g[i]) return dp[p][n][i] = 1;
        } else {
            if(v[p][n] == g[i]) return dp[p][n][i] = f(p, n-1, i) + 1;
        }
    }
    if(v[p][n] == g[i]) {
        dp[p][n][i] = f(1-p, n-1, i-1) + f(p, n-1, i);
    } else {
        dp[p][n][i] = f(p, n-1, i);
    }
    return dp[p][n][i];
}
int main() {
    scanf("%s", g);
    scanf("%s", v[0]);
    scanf("%s", v[1]);
    memset(dp, -1, sizeof(dp));
    vlen = strlen(v[0]);
    glen = strlen(g);
    printf("%d", f(0, vlen, glen) + f(1, vlen, glen));
    return 0;
}
