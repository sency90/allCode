#include <cstdio>
#pragma warning (disable:4996)

using namespace std;
typedef long long LL;
LL d[101][101][101];

LL building(int n, int l, int r) {
	if (l == 1 && r == 1) {
		if (n == 1) {
			return 1LL;
		}
		else {
			return 0LL;
		}
	}
	
	if (l < 1 || r < 1 || l + r > n + 1) {
		return 0LL;
	}
	

	if (d[n][l][r]) {
		return d[n][l][r];
	}
	
	return d[n][l][r] = ((n - 2)*building(n - 1, l, r) + building(n - 1, l - 1, r) + building(n - 1, l, r - 1)) % 1000000007LL;
}

int main() {
	int N, L, R;
	scanf("%d%d%d", &N, &L, &R);
	printf("%lld\n", building(N, L, R) % 1000000007LL);

	return 0;
}