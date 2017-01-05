#include<stdio.h>
#pragma warning (disable:4996)
#define MOD 1000000007;
int n;
int l;
int r;
int d[101][101][101];

int main() {
	int i;
	int j;
	int k;
	long long int temp;

	scanf("%d %d %d", &n, &l, &r);
	d[1][1][1] = 1;
	d[2][2][1] = d[2][1][2] = 1;
	for (i = 3; i <= n; i++)
	{
		d[i][i][1] = d[i][1][i] = 1;
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k <= n; k++)
			{
				temp = d[i - 1][j][k];
				temp = (temp*(i - 2)) % MOD;
				temp = (temp + d[i - 1][j - 1][k]) % MOD;
				temp = (temp + d[i - 1][j][k - 1]) % MOD;
				d[i][j][k] = temp;
			}
		}
	}
	printf("%d\n", d[n][l][r]);
	return 0;
}