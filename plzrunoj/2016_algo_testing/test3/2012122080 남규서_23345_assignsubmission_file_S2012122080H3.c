#include <stdio.h>

long long int arr[101][101][101];

int main(){
	int N = 0, R = 0, L = 0;
	scanf("%d %d %d", &N, &L, &R);

	arr[1][1][1] = 1, arr[2][2][1] = 1, arr[2][1][2] = 1;
	
	for(int i = 3; i<=N; i++){
		arr[i][i][1] = 1, arr[i][1][i] = 1;
		
		for(int j = 1; j<=N; j++){
			for(int k = 1; k<=N; k++){
					arr[i][j][k] = ((arr[i-1][j][k] * (i-2)) + arr[i-1][j-1][k] + arr[i-1][j][k-1]) % 1000000007;
					// 동적 프로그래밍을 사용하여 배열에 i, j, k에 해당되는 곳에 결과를 저장
			}
		}	
	}

	printf("%d\n", arr[N][L][R]);
	// N, R, L에 해당하는 배열값을 출력
	return 0;
}
