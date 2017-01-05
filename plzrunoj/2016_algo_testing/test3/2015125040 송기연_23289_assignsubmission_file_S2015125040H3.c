#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long dp[101][101][101];

long long building(int N, int L, int R) {
	if (N == 1 && L == 1 && R == 1) return 1; //���� ������ ���̴°� �ϳ��̰� �ǹ����� �ϳ���� 1�� ��ȯ
	else if (L ==1 && R ==1) return 0; //�ǹ����� �Ѱ��� �ƴ϶�� �Ұ����� ����̹Ƿ� 0�� ��ȯ
	else if (L < 1 || R < 1 || L + R - N > 1) return 0; //���� �����ʿ��� ���°� 1�� ���� ���ų� �¿� ��ģ�� ��ü �������� �߰� 1�� �������Ƿ� ���� 0

	if (dp[N][L][R]) return dp[N][L][R]; //����� ���̸� �״�� ��ȯ
	else {
		dp[N][L][R] = (building(N - 1, L - 1, R) + building(N - 1, L, R - 1) + building(N - 1, L, R)*(N - 2)) % 1000000007; //��������� �ʴٸ� ���
		return dp[N][L][R];
	}
}
int main() {
	int N;
	int L;
	int R;
	scanf("%d%d%d", &N, &L, &R);
	cout << building(N, L, R); //���
	return 0;
}
