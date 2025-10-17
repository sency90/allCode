#include <stdio.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))  

int main() {
	int num;
	int a[1000];
	int comp[1000] = { 0, };
	int count = 0;
	int max = 0;

	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &a[i]);
	}


	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (a[i] <= a[j]) {
				comp[i]++;
			}
		}
	}

	for (int i = 0; i < num; i++) {
		if (a[i] <= comp[i]) {
			max = MAX(a[i], max);
		}
	}
	printf("%d", max);
}