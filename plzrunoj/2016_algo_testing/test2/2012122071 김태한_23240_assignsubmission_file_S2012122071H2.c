#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int  main()
{
	int arr[1000];
	int n = 0;;
	int correct = 0;
	int i = 0;
	scanf("%d", &n);

	for (int k = 0; k < n; k++)
		scanf("%d", &arr[k]);

	qsort(arr, n, sizeof(int), compare);

	for (i = 0; i < n; i++)
	{
		if (n - i < arr[i])
			break;
	}
	printf("%d\n", arr[i - 1]);
}
