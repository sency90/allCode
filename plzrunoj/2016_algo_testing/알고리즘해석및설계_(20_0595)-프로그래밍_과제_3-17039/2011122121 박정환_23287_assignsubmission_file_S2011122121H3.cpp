#include <iostream>
#include <algorithm>

using namespace std;
const int MOD = 1000000007;
long long dp[101][101][101];

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	dp[1][1][1] = 1;
	dp[2][2][1] = 1;
	dp[2][1][2] = 1;

	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				dp[i][j][k] += dp[i - 1][j - 1][k]; dp[i][j][k] %= MOD;
				dp[i][j][k] += dp[i - 1][j][k - 1]; dp[i][j][k] %= MOD;
				dp[i][j][k] += dp[i - 1][j][k] * (i - 2); dp[i][j][k] %= MOD;
			}
		}
	}

	cout << dp[n][l][r] << endl;
	return 0;
}