#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long dp[101][101][101];

long long building(int N, int L, int R) {
	if (N == 1 && L == 1 && R == 1) return 1; //왼쪽 오른쪽 보이는게 하나이고 건물수가 하나라면 1을 반환
	else if (L ==1 && R ==1) return 0; //건물수가 한개가 아니라면 불가능한 경우이므로 0을 반환
	else if (L < 1 || R < 1 || L + R - N > 1) return 0; //왼쪽 오른쪽에서 보는게 1개 보다 적거나 좌우 합친게 전체 빌딩수의 추가 1을 못넘으므로 리턴 0

	if (dp[N][L][R]) return dp[N][L][R]; //저장된 값이면 그대로 반환
	else {
		dp[N][L][R] = (building(N - 1, L - 1, R) + building(N - 1, L, R - 1) + building(N - 1, L, R)*(N - 2)) % 1000000007; //저장되있지 않다면 계산
		return dp[N][L][R];
	}
}
int main() {
	int N;
	int L;
	int R;
	scanf("%d%d%d", &N, &L, &R);
	cout << building(N, L, R); //출력
	return 0;
}
