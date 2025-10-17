#include <stdio.h>

int main() {

	int num;
	int temp[1000];
	int count[1000] = {0};
	int result[1000];
	int i, j, k=0;

	scanf("%d", &num);
	if (num > 1000 || num < 0) {
		return;
	}
	for (i = 0; i < num; i++) {

		scanf("%d", &temp[i]);
	}
	for (i = 0; i < num; i++) {

		for (j = 0; j < num; j++) {
			if (temp[i] <= temp[j]) {
				count[i]++;

			}
		}
		if (count[i] >= temp[i]) {

			result[k] = temp[i];
			k++;
		}
	}
	j = 0;
	for (i = 0; i < k; i++) {
		if (result[j] <= result[i]) {
			j=i;
		}
	}

	printf("%d\n", result[j]);
	

}