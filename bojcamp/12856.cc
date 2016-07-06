#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAXN 100005
const int sz = 500;
typedef long long ll;
int n, Q, B[MAXN], beg[MAXN], fin[MAXN], cb[MAXN], c[MAXN];
ll sum[MAXN], cf[MAXN], f[MAXN];
int A(int x) {
	if (x < 0) x = -x;
	return x;
}
int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++) {
		c[i] = i;
		B[i] = i / sz;
		if (beg[B[i]] == 0) beg[B[i]] = i;
		fin[B[i]] = i;
	}
	for (int k = 1; k <= Q; k++) {
		int type, l, r, x; scanf("%d%d%d", &type, &l, &r);
		if (type == 1) {
			scanf("%d", &x);
			for (int i = l; i <= r; i++) {
				if (i == beg[B[i]] && fin[B[i]] <= r) {
					if (cb[B[i]] == 0) {
						for (int j = beg[B[i]]; j <= fin[B[i]]; j++) {
							if (cb[B[i]]) c[j] = cb[B[i]];
							sum[B[i]] += A(c[j] - x);
							f[j] += A(c[j] - x);
							c[j] = x;
						}
					}
					else {
						sum[B[i]] += (long long)(A(cb[B[i]] - x)) * (long long)(fin[B[i]] - beg[B[i]] + 1);
						cf[B[i]] += A(cb[B[i]] - x);
					}
					cb[B[i]] = x;
					i = fin[B[i]];
				}
				else {
					if (cb[B[i]]) {
						for (int j = beg[B[i]]; j <= fin[B[i]]; j++) c[j] = cb[B[i]];
						cb[B[i]] = 0;
					}
					f[i] += A(c[i] - x);
					sum[B[i]] += A(c[i] - x);
					c[i] = x;
				}
			}
		}
		else {
			ll res = 0;
			for (int i = l; i <= r; i++) {
				if (i == beg[B[i]] && fin[B[i]] <= r) {
					res += sum[B[i]];
					i = fin[B[i]];
				}
				else res += f[i] + cf[B[i]];
			}
			printf("%lld\n", res);
		}
	}
}