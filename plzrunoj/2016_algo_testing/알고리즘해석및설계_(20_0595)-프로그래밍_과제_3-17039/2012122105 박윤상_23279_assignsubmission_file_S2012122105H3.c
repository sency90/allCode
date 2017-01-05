#include <stdio.h>

int Num[101][101][101];

int main() {

	int num, left, right, i, j, k;
	long long int temp;
	
	scanf("%d", &num);
	scanf("%d", &left);
	scanf("%d", &right);
	
	Num[1][1][1] = 1;
	Num[2][2][1] = Num[2][1][2] = 1;

	for (i = 3; i <= num; i++) {
		Num[i][i][1] =  Num[i][1][i]=1;
		for (j = 1; j <= num; j++) {
			for (k = 1; k <= num; k++) {
				temp = Num[i - 1][j][k];
				temp = (temp * (i - 2)) % 1000000007;
				temp = (temp + Num[i - 1][j - 1][k]) % 1000000007;
				temp = (temp + Num[i - 1][j][k - 1]) % 1000000007;

				Num[i][j][k] = temp;
			}
			
		}
	}
	
	printf("%d\n", Num[num][left][right]);

	return 0;
}