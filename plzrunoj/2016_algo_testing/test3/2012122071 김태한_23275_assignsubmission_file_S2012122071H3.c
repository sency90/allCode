#include <stdio.h>
#include <memory.h>
long long dp[101][101][101] = { 0 };

int  main()
{
	const int MOD = 1000000007;
	dp[1][1][1] = 1;
	dp[2][2][1] = 1;
	dp[2][1][2] = 1;
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	for (int i = 3; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++)
			{
				dp[i][j][k] += dp[i - 1][j - 1][k]; dp[i][j][k] %= MOD;
				dp[i][j][k] += dp[i - 1][j][k - 1]; dp[i][j][k] %= MOD;
				dp[i][j][k] += dp[i - 1][j][k] * (i - 2); dp[i][j][k] %= MOD;
			}

	printf("%ld\n", dp[a][b][c] % MOD);
	return 0;
}

