

#include<stdio.h>


int main() {
	int n;

	printf("1-1000 ���� �ϳ� �Է��ϼ���");
	scanf_s("%d", &n);

	printf("%d ���� ���� �Է�\n", n);

	int array[1000] = { 0, };
	int count[1000] = { 0, };

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
	}

	for (int i = 0; i < n; i++) {
		if (array[i] != 0) {
			for (int j = 0; j < n; j++) {
				if (array[i] <= array[j]) {
					count[i]++;
				}
			}
		}
	}

	int max = 0;

	for (int i = 0; i < n; i++) {
		if (count[i] >= array[i]) {
			if (array[i] > max) {
				max = array[i];
			}
		}
	}

	printf("%d", max);

	return 0;

}