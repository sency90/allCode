#include <stdio.h>
#include <iostream>
using namespace std;

long long dp[101][101][101];

long long cal(int n,int l,int r)
{
	if((l+r)>n+1) return 0;
	if(n==0 || l==0 || r==0)
	{
		return 0;
	}
	if(n<l || n<r) return 0;

	if(dp[n][l][r]!=0) return dp[n][l][r];

	dp[n][l][r]=((n-2)*cal(n-1,l,r)+cal(n-1,l-1,r)+cal(n-1,l,r-1))%1000000007;
	return dp[n][l][r]%1000000007;
}

int main()
{
	int n,l,r;

	scanf("%d%d%d",&n,&l,&r);
	dp[1][1][1]=1;

	long long xxx=cal(n,l,r);

	printf("%d",xxx);
	return 0;
}