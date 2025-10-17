#include <stdio.h>


long long building[101][101][101];
int main() {

	int N, L, R;
	scanf_s("%d%d%d", &N, &L, &R);
	building[1][1][1] = 1LL;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				building[i][j][k] = building[i - 1][j - 1][k] + building[i - 1][j][k - 1] + building[i - 1][j][k] * (i - 2);
				building[i][j][k] %= 1000000007;
			}
		}
	}
	printf("%d\n", building[N][L][R]);
	return 0;
}