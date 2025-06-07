#include <stdio.h>
#define MAX 30

int size;
int sorted[MAX];

void merge(int a[], int m, int middle, int n)
{
	int i, j, k, l;
	for (i = m, j = middle + 1, k = m; i <= middle && j <= n; k++)
	{
		if (a[i] <= a[j])
		{
			sorted[k] = a[i];
			i++;
		}
		else
		{
			sorted[k] = a[j];
			j++;
		}
	}

	if (i>middle)
	{
		for (l = j; l <= n; l++, k++)
		{
			sorted[k] = a[l];
		}
	}
	else
	{
		for (l = i; l <= middle; l++, k++)
		{
			sorted[k] = a[l];
		}
	}
	for (l = m; l <= n; l++)
	{
		a[l] = sorted[l];
	}
}

void mergeSort(int a[], int m, int n)
{
	int middle;
	if (m<n)
	{
		middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}

}

int main(void)
{
	int t;
	int arr[500] = {0, };
	int brr[500] = {0, };
	size = 500;
	int nu;
	int temp;

	scanf_s("%i", &nu);

	if (nu > 500) {
		for (int i = 0; i < nu - 500; i++) {
			scanf_s("%i", &temp);
			arr[i] = temp;
		}
		for (int i = 500; i < nu; i++) {
			scanf_s("%i", &temp);
			brr[i] = temp;
		}
	}
	else {
		for (int i = 0; i < nu; i++) {
			scanf_s("%i", &temp);
			arr[i] = temp;
		}
	}

	mergeSort(arr, 0, size - 1);
	if (nu > 500) {
		mergeSort(brr, 0, size - 1);
	}

	//문제해결
	temp = 0;
	int cnt = 0;
	for (int i = 0; i<size; i++)
	{
		cnt++;
		if (cnt >= arr[500 - i - 1]) {
			temp = arr[500 - i - 1];
			break;
		}
	}
	if (nu > 500) {
		for (int i = 500; i < 1000; i++) {
			if (brr[500 - 1 - i] != 0) {
				cnt++;
			}
			if (cnt >= brr[500 - 1 - i]) {
				temp = brr[500 - 1 - i];
				break;
			}
		}
	}
	printf("%d",temp);

	return 0;
}