#include<stdio.h>

int n, l, r;
int ll[101][101][101];

int main()
{
	int num = 1000000007;
	int i, j, k;
	long long int floor;

	scanf("%d %d %d", &n, &l, &r);

	ll[1][1][1] = 1;
	ll[2][2][1] = ll[2][1][2] = 1;

	for (i = 3; i <= n; i++) {
		ll[i][i][1] = ll[i][1][i] = 1;
		for (j = 1; j <= n; j++) {
			for (k = 1; k <= n; k++) {
				floor = ll[i - 1][j][k];
				floor = (floor * (i - 2)) % num;
				floor = (floor + ll[i - 1][j - 1][k]) % num;
				floor = (floor + ll[i - 1][j][k - 1]) % num;

				ll[i][j][k] = floor;
			}
		}
	}

	printf("%d\n", ll[n][l][r]);
	while (1) {

	}
	return 0;
}
