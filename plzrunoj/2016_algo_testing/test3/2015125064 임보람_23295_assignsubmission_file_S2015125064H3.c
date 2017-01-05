#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

#define MOD 1000000007

int n, l, r;
int dp[101][101][101];

int main()
{
	int i, j, k;

	while(1) {
		scanf("%d %d %d", &n, &l, &r);
		if (n > 100 || n < 1 || l > n || r > n) {
			continue;
		}
		break;
	}

	dp[1][1][1] = 1;
	dp[2][2][1] = dp[2][1][2] = 1;

	for (i = 3; i <= n; i++) {
		dp[i][i][1] = dp[i][1][i] = 1;
		for (j = 1; j <= n; j++) {
			for (k = 1; k <= n; k++){
				dp[i][j][k] = (dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1]) % MOD;
			}
		}
	}
	printf("%d\n", dp[n][l][r]);

	return 0;
}