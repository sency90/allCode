#include<stdio.h>
long long result[101][101][101];
long long Check(int c, int l, int r) {
	result[1][1][1] = 1LL;
	for (int i = 2; i <= c; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				result[2][1][1] = 0;
				result[i][j][k] = result[i - 1][j - 1][k] + result[i - 1][j][k - 1] + result[i - 1][j][k] * (i - 2);
			}
		}
	}
	return result[c][l][r];
}
int main() {
	int count, l_count, r_count;
	scanf_s("%d %d %d", &count, &l_count, &r_count);
	printf_s("%lld", Check(count, l_count, r_count) % 1000000007LL);
	return 0;
}