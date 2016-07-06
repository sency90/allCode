#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, d;
long long x;
int getNextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}
int a[100005], b[100005];
int v[100005], vn;
set <pair <int, int> > s;
int main() {
	scanf("%d%d%I64d", &n, &d, &x);
	for (int i = 0; i < n; i = i + 1) {
		a[i] = i + 1;
	}
	for (int i = 0; i < n; i = i + 1) {
		swap(a[i], a[getNextX() % (i + 1)]);
	}
	for (int i = 0; i < n; i = i + 1) {
		if (i < d) b[i] = 1;
		else b[i] = 0;
	}
	for (int i = 0; i < n; i = i + 1) {
		swap(b[i], b[getNextX() % (i + 1)]);
	}
	for (int i = 0; i < n; i++) {
		if (b[i]) {
			v[++vn] = i;
		}
	}
	for (int i = 0; i < n; i++) {
		s.insert({ -a[i], i });
		int res = 0;
		if (i <= 500 || d <= 500) {
			for (int j = 1; j <= vn; j++) {
				if (v[j] > i) break;
				res = max(res, a[i - v[j]]);
			}
		}
		else {
			for (auto &z : s) {
				if (b[i - z.second]) {
					res = max(res, -z.first);
					break;
				}
			}
		}
		printf("%d\n", res);
	}
}