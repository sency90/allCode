#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;
long long Dynamic[100][100][100];
long long number = 1000000007;

long long Find(int x, int y, int z)
{
	Dynamic[1][1][1] = 1LL;

	for (int i = 2; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= z; k++) {
				Dynamic[i][j][k] = Dynamic[i - 1][j][k - 1] + Dynamic[i - 1][j - 1][k] + (i - 2) * Dynamic[i - 1][j][k];
				Dynamic[i][j][k] %= number;
			}
		}
	}
	return Dynamic[x][y][z];
}
int main()
{
	int Num, Left, Right;
	scanf("%d%d%d", &Num, &Left, &Right);
	printf("%lld", Find(Num, Left, Right));
	system("pause");
	return 0;
}
