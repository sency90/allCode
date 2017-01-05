#include <iostream> 

using namespace std;
long long s[101][101][101];
long long mod = 1000000007LL;

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	s[1][1][1] = 1LL;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				s[i][j][k] = s[i - 1][j - 1][k] + s[i - 1][j][k - 1] + s[i - 1][j][k] * (i - 2);
				s[i][j][k] %= mod;
			}
		}
	}
	cout << s[n][l][r] << '\n';
	return 0;
}
