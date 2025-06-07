#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int max_num(int arr[], int n, int size) {
	int num = 0;
	
	for (int i = 0; i < size; i++) {
		if (arr[n] <= arr[i]) {
			num++;
		}
	}
	
	return num;
}

int main() {
	int size;
	while (1) {
		scanf("%i", &size);
		if (1 <= size && size <= 1000) {
			break;
		}
		printf("size를 다시 입력하세요.\n");
	}

	int *arr = new int[size];
	for (int i = 0; i < size; i++) {
		scanf("%i", &arr[i]);
		if (0 > arr[i] || arr[i] > 10000) {
			i--;
		}
	}

	int max = -1;

	for (int i = 0; i < size; i++) {
		if (arr[i] <= max_num(arr, i, size)) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
	}

	printf("%i\n", max);

	return 0;
}