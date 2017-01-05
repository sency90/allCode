#include <stdio.h>

int arr[101][101][101];		//배열의 시작점을 0이아닌 1부터로 생각
int Building(int N, int L, int R) {
	int ans;
	arr[1][1][1] = 1;
	for (int n = 2; n <= N; n++) {
		for (int l = 1; l <= L; l++) {
			for (int r = 1; r <= R; r++) {
				arr[n][l][r] = arr[n - 1][l - 1][r] + arr[n - 1][l][r - 1] + arr[n - 1][l][r] * (n - 2);
				ans = arr[n][l][r];
				/*N개의 건물을 높은 건물부터 세운다고 생각. (N-1)높이의 건물을 짓고 (N-2) ... 1높이 건물까지 짓는다.
				건물이 왼쪽에 지어질땐 n과 l이 1증가, 오른쪽에 지어질땐 n과 r이 1증가, 사이에 지어질 땐 p만 1증가한다.
				p만 1증가하는 경우는 1......n개의 건물이있을 때 (n-2)경우가 있으므로 이를 곱하여 더해준다.*/
			}
		}
	}
	return ans;		//반환값
}

int main() {
	int num, left, right;		//입력 값
	int m = 1000000007;
	scanf_s("%d %d %d", &num, &left, &right);
	printf_s("%d", Building(num, left, right) % m);
}