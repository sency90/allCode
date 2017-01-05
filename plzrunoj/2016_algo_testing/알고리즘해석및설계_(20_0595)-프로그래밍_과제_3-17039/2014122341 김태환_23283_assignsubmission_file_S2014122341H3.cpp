#include<cstdio>
#include<iostream>
#define mod 1000000007LL;
using namespace std;
long long dp[101][101][101];

long long f(int n, int l, int r)
{
	if(n==1 && l==1 && r==1){ // ��尡 1�̰� l�� 1 r�� 1�϶� ������ Ƚ���� 1����
		return 1LL;
	}
	else if(l==0 || r==0 || n==0 || r+l>n+1)	{ // ����� ���� 0�̰ų� ���� �������� 0�̸� �������� ���� ����. ���� �� ������ ���� n+1�� ��������. 
		return 0LL;
	}
	if(dp[n][l][r]) return dp[n][l][r]; // ���� ����� ���� ������ ����. 

	return dp[n][l][r]=(f(n-1,l-1,r)+f(n-1,l,r-1)+(f(n-1,l,r)*(n-2)))%mod; // dp�� ���. ���������� ������ ��尪�� �� �� ����� ���� Ƚ��. 
}

int main()
{
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	cout<<f(n,l,r)<<"\n";
	return 0;
}