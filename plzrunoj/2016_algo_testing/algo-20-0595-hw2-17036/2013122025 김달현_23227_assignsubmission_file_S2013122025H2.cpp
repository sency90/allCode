#include <stdio.h>

int x = -1;	//���ϰ��� �ϴ� ��

void Homework(int num, int arr[]) {			//������ ������ ������ �迭�� �޾� x���� ���Ѵ�.
	for (int i = 0; i < num; i++) {
		int count = 0;		//������ ���Һ��� ũ�ų� ���� ������ ����
		if (arr[i] == num || arr[i] < num) {	//���� ���Ұ��� ������ �������� �۰ų� ���� ��
			for (int j = 0; j < num; j++) {
				if (arr[i] < arr[j] || arr[i] == arr[j]) {	//���� ���Һ��� ũ�ų� ������ count�� 1�� �����ش�.
					count++;
				}
			}
		}
		if (count >= arr[i] && x < arr[i]) {	//count�� ���� ���� ���Һ��� ũ�ų� ����. AND ���� ���Ұ� x�� ����� ������ ũ��.
			x = arr[i];		//x�� ���� ���Ұ��� �ִ´�.
		}
	}
}

int main() {
	int n;	//������ ����
	int input[1000];	//n�� ������ �Է¹��� �迭

	scanf_s("%d", &n);	//������ ������ �Է¹޴´�.
	if (n > 1000 || n < 1) {
		printf_s("n�� 1�̻� 1,000������ �����Դϴ�.");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &input[i]);	//n���� ������ �Է¹޴´�.
		if (input[i] > 10000 || input[i] < 0) {
			printf_s("0���� 10,000������ ������ �Է����ּ���.");
			return 0;
		}
	}

	Homework(n,input);
	if (x == -1) {
		printf_s("������ �����ϴ� ������ �������� �ʽ��ϴ�.");
	}
	else {
		printf_s("%d", x);
	}
}