#include<stdio.h>
int d[100][100][100] = {0};


int f(int N,int R,int L) {
	if (d[N][R][L]) {
		return d[N][R][L];
	}
	else if (L < 1 || R < 1 || L+R > N+1) {
		return 0;
	}
	if (N == 1 && R == 1 && L == 1) {
		d[N][R][L] = 1;
		return d[N][R][L];
	}
	d[N][R][L] = f(N - 1,R - 1,L) + f(N - 1,R,L - 1) + ((N - 2) * f(N - 1,R,L));

	return d[N][R][L]%1000000007;
}


int main() {
	int N, R, L;
	scanf("%d %d %d",&N,&R,&L);
	printf("%d\n", f(N, R, L));
	return 0;
}