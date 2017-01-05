#include<stdio.h>
using namespace std;

typedef long long typel;

typel dp[101][101][101];
int mod = 1e9 + 7LL;

//입력에 따른 제한과 점화식 풀이 
typel solve(int nB, int l, int r) {
	if (l == 1 && r == 1) {
		if (nB == 1) {
			return 1LL;
		}
		else {
			return 0LL;
		}
	}
	else if (l < 1 || r < 1 || l + r > nB + 1) {
		return 0LL;
	}

	if (dp[nB][l][r]) {
		return dp[nB][l][r];
	}
	//점화식 풀이 
	else {
		dp[1][1][1] = 1LL;
		for (int i = 2; i <= nB; i++) {
			for (int j = 1; j <= l; j++) {
				for (int k = 1; k <= r; k++) {
					dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2);
					dp[i][j][k] %= mod;
				}
			}
		}
		return dp[nB][l][r];
	}
}

int main() {
	int n, l, r;
	int result;
	scanf("%d%d%d", &n, &l, &r);

	result = solve(n, l, r);
	
	printf("%d\n", result);

	return 0;
}