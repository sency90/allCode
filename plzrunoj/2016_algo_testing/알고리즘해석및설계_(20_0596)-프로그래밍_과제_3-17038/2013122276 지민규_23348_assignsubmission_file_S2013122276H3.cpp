#include <cstdio>
#include <algorithm>

using namespace std;

long long Dynamic[101][101][101];

int main()
{
	int N, L, R;
	scanf("%d%d%d", &N, &L, &R);
	Dynamic[1][1][1] = 1LL;

	for(int i = 2; i <= N; i++)
		for(int j = 1; j <= L; j++)
			for (int k = 1; k <= R; k++)
			{
				Dynamic[i][j][k] = Dynamic[i - 1][j][k - 1] + Dynamic[i - 1][j - 1][k] + Dynamic[i - 1][j][k] * (i - 2);
				Dynamic[i][j][k] %= 1000000007LL;
			}

	printf("%lld", Dynamic[N][L][R]);
}