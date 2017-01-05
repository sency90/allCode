#include <cstdio>
#include <cstring>
using namespace std;

long long dp[102][102][102];

long long find(int n, int l, int r){
	if(dp[n][l][r] != -1){
		return dp[n][l][r];
	}
	else{
		long long first, second, third;
		if(dp[n-1][l][r]!= -1 && dp[n-1][l][r]!= 0)
			first = dp[n-1][l][r];
		else if(dp[n-1][l][r] == 0)
			first = 0;
		else
			first = find(n-1,l,r);

		if(dp[n-1][l-1][r] != -1 && dp[n-1][l-1][r] != 0)
			second = dp[n-1][l-1][r];
		else if(dp[n-1][l-1][r] == 0)
			dp[n-1][l-1][r] = 0;
		else
			second = find(n-1,l-1,r);

		if(dp[n-1][l][r-1] != -1 && dp[n-1][l][r-1] != 0)
			third = dp[n-1][l][r-1];
		else if(dp[n-1][l][r-1] == 0)
			third = 0;
		else
			third = find(n-1,l,r-1);

		return dp[n][l][r] = (first*(n-2)+second+third)%1000000007;
	}

}

int main(){
	int n,l,r;
	
	scanf("%d%d%d",&n,&l,&r);
	dp[1][1][1] = 1;
	for(int i=1;i<=n;i++)
		for(int k=1;k<=n;k++)
			for(int j=1;j<=n;j++)
				dp[i][k][j] = -1;

	for(int i=1; i<101; i++){
		dp[i][i][1] = 1;
		dp[i][1][i] = 1;
		dp[i+1][i+1][i+1] = -1;
	}
	printf("%lld",find(n,l,r));
	return 0;
}