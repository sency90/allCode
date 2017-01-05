#include<stdio.h>
#include <iostream>
using namespace std;
long long ans[101][101][101] = { 0 };

int Building(long long N,long long L,long long R)
{
	if (ans[N][L][R])
	{
		return ans[N][L][R];
	}
	if (N <= 0 || L <= 0 || R <= 0)
	{
		return 0;
	}
	if (N + 1 < L + R)
	{
		ans[N][L][R] = 0;
		return ans[N][L][R];
	}
	ans[N][L][R] = ((N - 2)*Building(N - 1, L , R ) + Building(N - 1, L, R - 1) + Building(N - 1, L - 1, R)) % 1000000007;
	return(ans[N][L][R]);
}

int main()
{
	int N, L, R;
	scanf("%d%d%d", &N, &L, &R);
	ans[1][1][1] = 1;
	Building(N, L, R);
	cout << ans[N][L][R] << endl;
	return 0;
}