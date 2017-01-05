
#include "stdafx.h"
#include<stdio.h>
#include<iostream>


using namespace std;

int N, L, R;

#define F long long int 
#define A 1000000007
F dp[101][101][101];
F solve(int n, int l, int r)
{
	if ((l == 1 && r == n) || (l == n && r == 1)) return 1;
	if (l == 0 || r == 0) return 0;
	F & ret = dp[n][l][r];
	if (ret != -1) return ret;

	ret = 0;

	ret = ((solve(n - 1, l, r)*(n - 2)) + (solve(n - 1, l - 1, r)) + (solve(n - 1, l, r - 1))) % A;

	return ret;
}
int main()
{
	cin >> N >> L >> R;
	memset(dp, -1, sizeof(dp));

	cout << ((solve(N, L, R)) % A) << endl;
	system("pause");
}
