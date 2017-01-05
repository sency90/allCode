#include<stdio.h>

using namespace std;

int num[101][101][101];

int main()
{
	
	int N=0;		//전체 빌딩수
	int L=0;		//왼쪽에서 보았을 때 보이는 빌딩 수
	int R=0;		//오른쪽에서 보았을 때 보이는 빌딩 수 

	scanf("%d", &N);
	if (N < 1 || N > 100) {
		return 0;
	}
	printf("%\n\n");

	scanf("%d", &L);
	scanf("%d", &R);
	
	num[1][1][1] = 1;

	for (int n = 2; n <= N; n++) {
		for (int l = 1; l <= L; l++) {
			for (int r = 1; r <= R; r++) {
				num[n][l][r] = num[n - 1][l - 1][r] + num[n - 1][l][r - 1] + num[n - 1][l][r] * (n - 2);
				num[n][l][r] %= 1000000007;
			}
		}
	}
	
	printf("%d",num[N][L][R]);
}

