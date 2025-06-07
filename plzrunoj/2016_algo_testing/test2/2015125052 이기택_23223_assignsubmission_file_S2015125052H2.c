#include<stdio.h>

int main() {
	int count = 0;
	int num[10000];
	int ans = 0;
	int k;
	int j;
	int temp = 0;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%d", &num[i]);
	}

	for ( k = 0; k < count; k++) {
		for ( j = k + 1; j < count; j++) {
			if (num[j] < num[k]) {
				temp = num[k];
				num[k] = num[j];
				num[j] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		if (count - i >= num[i]) {
			ans = num[i];
		}
	}

	printf("%d", ans);

	return 0;
}