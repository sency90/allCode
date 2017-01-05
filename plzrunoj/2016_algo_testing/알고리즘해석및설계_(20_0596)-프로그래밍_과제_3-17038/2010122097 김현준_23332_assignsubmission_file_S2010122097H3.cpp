#include <stdio.h>
#pragma warning(disable:4996) 

const int t = 1000000007;
long long dp[101][101][101];

int main()
{
	int n, l, r;
	dp[1][1][1] = 1;
	dp[2][2][1] = 1;
	dp[2][1][2] = 1;
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			for (int k = 1; k <= r; k++)
			{
				dp[i][j][k] += dp[i - 1][j - 1][k];
				dp[i][j][k] %= t;
				dp[i][j][k] += dp[i - 1][j][k - 1];
				dp[i][j][k] %= t;
				dp[i][j][k] += dp[i - 1][j][k] * (i - 2);
				dp[i][j][k] %= t;
			}
		}
	}
	printf("%lld", dp[n][l][r] % t);
	return 0;
}