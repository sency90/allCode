#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

long long dp[101][101][101];

long long f(int N, int L, int R) {
	if (N == 1) {
		if (L == 1 && R == 1) return 1;
		else return 0;
	}
	if (L < 1 || R < 1 || (L + R) > N+1 ) return 0;

	if (dp[N][L][R]) 
		return dp[N][L][R]; 
	else
		return dp[N][L][R] = (f(N - 1, L - 1, R) + f(N - 1, L, R - 1)+(N - 2)*f(N -1, L, R))%1000000007;
}

int main(){
	int n,l,r;
	scanf("%d %d %d", &n, &l, &r);

	printf("%lld", f(n, l, r));
	return 0;
}