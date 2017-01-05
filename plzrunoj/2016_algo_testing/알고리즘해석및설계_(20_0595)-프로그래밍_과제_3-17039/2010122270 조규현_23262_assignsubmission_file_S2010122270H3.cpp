#include <cstdio>
int n, r, l, i, j, k;
long long dp[101][101][101];
int main(){
	scanf("%d%d%d", &n, &r, &l);
	dp[1][1][1] = 1;
	for (i = 2; i <= n; i++)for (j = 0; j <= i; j++)for (k = 0; k <= i; k++)
		dp[i][j][k] = (dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1]) % 1000000007;
	printf("%lld\n", dp[n][r][l]);
}