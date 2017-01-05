#include <stdio.h>
long long D[101][101][101] = { 0 };

int func(int N, int L, int R) {
	if (L == 1 && R == 1) {
		if (N == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (L < 1 || R < 1 || L + R > N + 1) return 0;
	if (D[N][L][R]) return D[N][L][R];
	D[N][L][R] = func(N - 1, L - 1, R) + func(N - 1, L, R - 1) + func(N - 1, L, R) * (N - 2);
	return D[N][L][R] % 100000007;
}

int main() {
	int N, L, R;
	scanf_s("%d %d %d", &N, &L, &R);
	printf("%d", func(N, L, R));
	return 0;
}