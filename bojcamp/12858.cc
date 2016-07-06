#include <stdio.h>
#define MAXN 100005
typedef long long ll;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int n, x[MAXN], bn;
ll seg[4 * MAXN], sum[4 * MAXN];
ll f(ll X) {
	if (X < 0) X = -X;
	return X;
}
void upd(int p, int v) {
	seg[p] += v; sum[p] += v;
	p /= 2;
	while (p) {
		seg[p] = gcd(seg[p * 2], seg[p * 2 + 1]);
		sum[p] += v;
		p /= 2;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	bn = 1; while (bn < n) bn *= 2; bn--;
	for (int i = 1; i <= n; i++) upd(bn + i, x[i] - x[i - 1]);
	int m; for (scanf("%d", &m); m--; ) {
		int v, l, r, L, R; scanf("%d%d%d", &v, &l, &r); L = l, R = r;
		if (v == 0) {
			l += bn + 1; r += bn;
			ll res = 0, val = 0;
			while (l <= r) {
				if (l == r) {
					res = gcd(res, f(seg[l]));
					break;
				}
				if (l & 1) res = gcd(res, f(seg[l]));
				if (!(r & 1)) res = gcd(res, f(seg[r]));
				l = (l + 1) / 2;
				r = (r - 1) / 2;
			}
			R = bn + L; L = bn + 1;
			while (L <= R) {
				if (L == R) {
					val += sum[L];
					break;
				}
				if (L & 1) val += sum[L++];
				if (!(R & 1)) val += sum[R--];
				L /= 2; R /= 2;
			}
			res = gcd(res, val);
			printf("%lld\n", res);
		}
		else {
			upd(bn + l, v);
			if (r + 1 <= n) upd(bn + r + 1, -v);
		}
	}
}