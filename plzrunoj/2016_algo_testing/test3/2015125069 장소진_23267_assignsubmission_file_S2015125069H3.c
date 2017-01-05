#include <iostream>
using namespace std;

int n, r, l;
long long dp[101][101][101];

int main() {
	cin >> n >> r >> l;
	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= i; k++)
				dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2)) % 1000000007;
	cout << dp[n][r][l];
}