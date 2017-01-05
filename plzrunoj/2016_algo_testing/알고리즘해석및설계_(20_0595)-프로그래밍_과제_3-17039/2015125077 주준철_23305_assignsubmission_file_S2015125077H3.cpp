#include <cstdio>
#include <cstring>
long long d[111][111][111];
#define mod 1000000007
long long go(int n, int l, int r) {
	if (n <= 0 || l <= 0 || r <= 0) return 0;
	if (d[n][l][r] != -1) return d[n][l][r];
	return d[n][l][r] = (go(n - 1, l - 1, r)
		+ go(n - 1, l, r - 1)
		+ go(n - 1, l, r)*(n - 2)) % mod;
}
int main() {
	int n, l, r;
	scanf_s("%d %d %d", &n, &l, &r);
	memset(d, -1, sizeof(d));
	d[1][1][1] = 1;
	printf("%lld\n", go(n, l, r));
	return 0;
}