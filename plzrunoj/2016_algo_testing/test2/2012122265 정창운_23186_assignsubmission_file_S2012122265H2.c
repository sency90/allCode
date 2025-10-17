#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

int main() {
	int n = 0;
	int *x;
	int *index_x;
	int max = 0;
	int cnt = 0;

	scanf("%d", &n);
	if (n > 1000 || n < 1)
	{
		printf("range error!\n");
		exit(0);
	}
	x = new int[n];
	index_x = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
		if (x[i] > 10000 || x[i] < 0)
		{
			printf("range error!\n");
			exit(0);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (x[i] <= x[j])
				cnt++;
		}

		index_x[i] = cnt;
		cnt = 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (x[i] <= index_x[i])
		{
			max = MAX(max, x[i]);
		}
	}

	printf("%d\n", max);

	delete[] x;
	delete[] index_x;

	return 0;
}