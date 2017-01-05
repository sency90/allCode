#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int find(int array[], int n) {
	int *count = new int[n];	//x���� ���ų� ū ���ڰ� �� �� �������� �����ϴ� �迭
	int i = 0, j = 0, temp = 0, t = -1;

	//���� ������������ ���� - �������� �̿�
	for (i = 0; i < n - 1; i++)
	{
		int index = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[index] > array[j])
			{
				index = j;
			}
		}
		temp = array[index];
		array[index] = array[i];
		array[i] = temp;
	}
	
	for (i = 0; i < n; i++) {
		//���ų� ū �� ����
		count[i] = n - i;
		
		if (count[i] >= array[i]) {
		//x���� ���ų� ū ���ڰ� x�� �̻� ������ ���
			if (count[i] >= t) {
				t = array[i];	//���ų� ū ������ ������ ���� ���� x
			}
		}
	}
	return t;
}

void main() {
	int n;
	int result;

	while (true) {
		//������ ���� �Է�
		scanf("%d", &n);
	
		if (n > 1000 || n < 1) {
			printf("1~1000 ���� �� �Է�\n");
			continue;
		}
		break;
	}
	int *array = new int[n];

	while (true) {
		//������ �Է�
		int rp = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &array[i]);
			
			if (array[i] < 0 || array[i]>10000) {
				printf("0~10000 ���� �� �Է�\n");
				rp = -1;
			}
		}
		if (rp != 0) {
			continue;
		}
		else {
			break;
		}
	}
	
	result = find(array, n);

	printf("%d\n", result);
}