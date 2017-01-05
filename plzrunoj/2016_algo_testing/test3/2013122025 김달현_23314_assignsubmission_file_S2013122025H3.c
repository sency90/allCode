#include <stdio.h>

int arr[101][101][101];		//�迭�� �������� 0�̾ƴ� 1���ͷ� ����
int Building(int N, int L, int R) {
	int ans;
	arr[1][1][1] = 1;
	for (int n = 2; n <= N; n++) {
		for (int l = 1; l <= L; l++) {
			for (int r = 1; r <= R; r++) {
				arr[n][l][r] = arr[n - 1][l - 1][r] + arr[n - 1][l][r - 1] + arr[n - 1][l][r] * (n - 2);
				ans = arr[n][l][r];
				/*N���� �ǹ��� ���� �ǹ����� ����ٰ� ����. (N-1)������ �ǹ��� ���� (N-2) ... 1���� �ǹ����� ���´�.
				�ǹ��� ���ʿ� �������� n�� l�� 1����, �����ʿ� �������� n�� r�� 1����, ���̿� ������ �� p�� 1�����Ѵ�.
				p�� 1�����ϴ� ���� 1......n���� �ǹ������� �� (n-2)��찡 �����Ƿ� �̸� ���Ͽ� �����ش�.*/
			}
		}
	}
	return ans;		//��ȯ��
}

int main() {
	int num, left, right;		//�Է� ��
	int m = 1000000007;
	scanf_s("%d %d %d", &num, &left, &right);
	printf_s("%d", Building(num, left, right) % m);
}