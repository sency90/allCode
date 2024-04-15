#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll a[200001], b[200001], dp[200001][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		memset(dp, 0, sizeof(dp));
		int n,m;
		cin >> n >> m;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		for(int i=1; i<=n; i++) {
			cin >> b[i];
		}
		dp[n][0] = a[n];
		dp[n][1] = b[n];

		for(int i=n; i>=2; i--) {
			dp[i-1][0] = min(dp[i][1]+a[i-1], dp[i][0]+a[i-1]);
			dp[i-1][1] = min(dp[i][0]+b[i-1], dp[i][1]+b[i-1]);
		}
		ll mn = 0x3f3f3f3f;
		for(int i=1; i<=m; i++) {
			mn = min(mn, dp[i][0]);
		}
		cout << mn << "\n";
	}
	return 0;
}
