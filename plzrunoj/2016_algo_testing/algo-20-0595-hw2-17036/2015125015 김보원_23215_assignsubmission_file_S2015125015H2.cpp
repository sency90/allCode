#include<stdio.h>

using namespace std;

//���� ã�Ƴ��� �Լ�
int sort(int n, int Array_1[]) {
	int i, j, temp;
	int k, l, p; 
	int count = 0;
	int result;
	int* Array_2 = new int[n];
	int* Array_3 = new int[n];

	//�Է°� ����
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (Array_1[j] > Array_1[j + 1]) {
				temp = Array_1[j];
				Array_1[j] = Array_1[j + 1];
				Array_1[j + 1] = temp;
			}
		}
	}

	count = n;
	
	//�ڱ⺸�� ū ���� ��ִ��� count 
	for (k = 0; k < n; k++) {
		Array_2[k] = count;
		count--;
	}

	//���ǿ� �´°� ǥ�� 
	for (l = 0; l < n; l++) {
		if (Array_1[l] <= Array_2[l]) {
			Array_3[l] = 1;
		}
	}
	
	//�ش� ���� �� ���� ū���� �ش��ϴ� �� ã�� 
	for (p = 0; p < n; p++) {
		if (Array_3[p] == 1) {
			result = p;
			}
	}

	//����� ���
	printf("%d\n", Array_1[result]);

	return 0;
}

//main()�Լ� 
int main() {
	int n;
	scanf("%d", &n);
	if (n < 1 || n > 1000) {
		printf( "���� ���� ����. ���α׷� ���� (1~1000)" );
		return 0;
	}
	int* Array_1 = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &Array_1[i]);
	}

	for (int i = 0; i < n; i++) {
		if ((Array_1[i] > 10000) || (Array_1[i] < 0)) {
			printf ("���� ���� ����. ���α׷� ����(0~10000)" );
			return 0;
		}
	}

	//����� ã�� �Լ� ����
	sort(n, Array_1);

	return 0;
}