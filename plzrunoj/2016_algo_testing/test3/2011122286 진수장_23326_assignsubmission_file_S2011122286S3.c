#include <cstdio>
using namespace std;
const int MOD = 1000000007;

int n, l, r;
int dp[101][101][101];

int main()
{
	int i, j, k;
	long long int temp;

	scanf("%d %d %d", &n, &l, &r);

	dp[1][1][1] = 1;
	dp[2][2][1] = dp[2][1][2] = 1;

	for (i = 3; i <= n; i++) {
		dp[i][i][1] = dp[i][1][i] = 1; //계산식 오름차순 정렬 case
		for (j = 1; j <= n; j++) {
			for (k = 1; k <= n; k++) { //점화식 적용 dp[n][l][r] = (n-2)*dp[n-1][r][l] + dp[n-1][r][l-1] + dp[n-1][r-1][l]
				temp = dp[i - 1][j][k];
				temp = (temp * (i - 2)) % MOD;
				temp = (temp + dp[i - 1][j - 1][k]) % MOD;
				temp = (temp + dp[i - 1][j][k - 1]) % MOD;

				dp[i][j][k] = temp;
			}
		}
	}

	printf("%d\n", dp[n][l][r]);

	return 0;
}
