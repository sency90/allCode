#include <cstdio>
#include <cstdlib>
using namespace std;

int compare(void *t, const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int n;
	scanf_s("%i", &n);

	int* arr = new int[n];
	for (int i = 0; i < n; i++) scanf_s("%i", &arr[i]);
	qsort_s(arr, n, sizeof(arr[0]), compare, NULL);
	
	for (int i = 1; i <= n; i++) {
		if (arr[n - i] <= i) {
			printf_s("%i\n", arr[n - i]);
			break;
		}
	}

	return 0;
}