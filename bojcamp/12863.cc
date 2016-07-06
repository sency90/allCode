#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

typedef long long ll;

const ll MOD = 1000000007;
inline ll getmod(ll x) {
	x %= MOD;
	return x;
}

ll getval2(ll n, ll x) {
	if (n < x) return n * (n + 1) / 2;
	else {
		ll rv = x * (x + 1) / 2;
		rv += (n - x) * x;
		return rv;
	}
}
ll getval(ll n, ll x) {
	ll rv = 0;
	rv += getval2(n / 2, x);
	rv += getval2(n - n / 2, x);
	rv %= MOD;
	return rv;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		ll n, m, k, s;
		scanf("%lld %lld %lld %lld", &n, &m, &k, &s);

		ll ans = 0;

		ans += getmod(getmod((n - k + 1) * (n - s + 1)) * getmod(m*(m - 1)));
		if (n + 2 - s - k >= 2) ans += getmod(m * getmod((n + 2 - s - k)*(n + 1 - s - k)));
		ans += getmod(getmod((m - k + 1) * (m - s + 1)) * getmod(n*(n - 1)));
		if (m + 2 - s - k >= 2) ans += getmod(n * getmod((m + 2 - s - k)*(m + 1 - s - k)));
		ans += getmod(getmod(getmod(m*n) * (n - k + 1)) * (m - s + 1));
		ans += getmod(getmod(getmod(m*n) * (n - s + 1)) * (m - k + 1));

		ll t1 = 0, t2 = 0;
		t1 = getval(n, min(n - k + 1, k));
		t2 = getval(n, min(n - s + 1, s));
		ans -= getmod(getmod(s*getmod(t1))*(m - s + 1));
		ans -= getmod(getmod(k*getmod(t2))*(m - k + 1));

		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		printf("Case %d: %lld\n", tc, (ans * 4) % MOD);
	}
	return 0;
}