#include <stdio.h>

void merge(int num[], int start, int median, int end) {
	int i, j, k, m, n;
	int tempArr[1000];
	i = start;
	j = median + 1;
	k = start;

	while (i <= median && j <= end)
		tempArr[k++] = (num[i] > num[j]) ? num[j++] : num[i++];
	m = (i > median) ? j : i;
	n = (i > median) ? end : median;

	for (; m <= n; m++)
		tempArr[k++] = num[m];
	for (m = start; m <= end; m++)
		num[m] = tempArr[m];
}

void merge_sort(int num[], int start, int end) {
	int median = (start + end) / 2;
	if (start < end) {
		merge_sort(num, start, median);
		merge_sort(num, median + 1, end);
		merge(num, start, median, end);
	}

}

void tracer(int num[], int len) {
	int i;
	for (i = 0; i<len; i++)
		printf("%d\t", num[i]);
	printf("\n\n");
}

int main(void) {
	int testArr[1000];
	int N;
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &testArr[i]);
	merge_sort(testArr, 0, N - 1);
	//tracer(testArr, N);
	int count1 = 0;
	int count2 = 0;
	int Arr[1000] = {0};
	/*
	int len;
	len = N;
	for (i = 0; i < N; i++) {
		if (testArr[i] == testArr[i + 1])
			len -= 1;
	}
	*/
	for (i = 0; i < N; i++) {
		count1 = N - i;
		if (count1 >= testArr[i]) {
			Arr[count2] = count1;
			count2++;
		}
	}
	for (i = 0; i<count2; i++) {
		if (Arr[i + 1] == 0)
			printf("%d\n",testArr[i]);
	}
	return 0;
}
