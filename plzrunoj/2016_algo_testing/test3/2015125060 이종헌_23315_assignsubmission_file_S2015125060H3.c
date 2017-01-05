#include <cstdio>

using namespace std;

typedef long long ll;

ll result[101][101][101];
ll mod = 1e9 + 7ll;

ll solve(int n, int l, int r) {
	if(l == 1 && r == 1) {
		if(n == 1) {
			return 1ll;
		} else {
			return 0ll;
		}
	} 
	
	if(l < 1 || r < 1 || l + r > n + 1) {
		return 0ll;
	}
	
	if(result[n][l][r]) {
		return result[n][l][r];
	} else {
		return result[n][l][r] = ((n - 2) * solve(n - 1, l, r) + solve(n - 1, l - 1, r) + solve(n - 1, l, r -1)) % mod;
	}
}

int main() {
	int n, l, r;
	ll res;

	scanf("%d%d%d", &n, &l, &r);
	res = solve(n, l, r);
	printf("%lld\n", res);
	return 0;
}