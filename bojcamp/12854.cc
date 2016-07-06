#include <stdio.h>
int n, m;
double x[505], res;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lf", x + i);
	for (int i = 1; i <= m; i++) {
		int a, b; double c; scanf("%d%d%lf", &a, &b, &c);
		if ((x[a] + x[b]) / c > res) res = (x[a] + x[b]) / c;
	}
	printf("%.6lf", res);
}