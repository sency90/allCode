#include <iostream>
#include <cstdio>

using namespace std;

long long int bld[101][101][101];

int main()
{
	int ansN, ansL, ansR;

	scanf("%d %d %d", &ansN, &ansL, &ansR);

	bld[1][1][1] = 1;

	for (int n = 2; n <= ansN; n++)
	{
		for (int l = 1; l <= ansL; l++)
		{
			for (int r = 1; r <= ansR; r++)
			{
				bld[n][l][r] = bld[n - 1][l - 1][r] + bld[n - 1][l][r - 1] + (bld[n - 1][l][r] * (n - 2));
				bld[n][l][r] %= 1000000007;
			}
		}
	}

	printf("%lld", bld[ansN][ansL][ansR]);
}
