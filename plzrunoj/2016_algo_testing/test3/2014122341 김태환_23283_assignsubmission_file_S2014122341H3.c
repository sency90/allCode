#include<cstdio>
#include<iostream>
#define mod 1000000007LL;
using namespace std;
long long dp[101][101][101];

long long f(int n, int l, int r)
{
	if(n==1 && l==1 && r==1){ // 노드가 1이고 l이 1 r이 1일땐 무조건 횟수는 1가지
		return 1LL;
	}
	else if(l==0 || r==0 || n==0 || r+l>n+1)	{ // 노드의 수가 0이거나 왼쪽 오른쪽이 0이면 가지수가 존재 안함. 우측 과 좌측의 합은 n+1을 넘지못함. 
		return 0LL;
	}
	if(dp[n][l][r]) return dp[n][l][r]; // 현재 노드의 값이 있으면 리턴. 

	return dp[n][l][r]=(f(n-1,l-1,r)+f(n-1,l,r-1)+(f(n-1,l,r)*(n-2)))%mod; // dp를 사용. 가짓수에서 현재의 노드값을 왼 우 가운데에 있을 횟수. 
}

int main()
{
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	cout<<f(n,l,r)<<"\n";
	return 0;
}