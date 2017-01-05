#include <cstdio>
using namespace std;

long long table[101][101][101] = { 0 };
long long building(int n, int l, int r) {
	if (l < 1 || r<1 || l + r>n + 1) return 0;
	else if (n == 1) return 1;

	if (table[n][l][r]) return table[n][l][r];
	else return table[n][l][r] = ((n - 2) * building(n - 1, l, r) + building(n - 1, l - 1, r) + building(n - 1, l, r - 1)) % 1000000007;
}

int main() {
	int n, l, r;
	scanf_s("%i %i %i", &n, &l, &r);

	printf_s("%lli\n", building(n, l, r));

	return 0;
}