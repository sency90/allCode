#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long d[101][101][101];
long long number = 1000000007;

long long f(int x, int l, int r) {
	if (l == 1 && r == 1) {
		if (x = 1)return 1LL;
		else return 0LL;
	}
	else if (l<1 || r<1 || l + r>x + 1) return 0LL;
	if (d[x][l][r]) return d[x][l][r];
	d[x][l][r] = (x - 2)*f(x - 2, l, r) + f(x - 1, l - 1, r) + f(x - 1, l, r - 1);
	d[x][l][r] %= number;
}

int main() {
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	printf("%lld",f(n,l,r));
	return 0;
}



