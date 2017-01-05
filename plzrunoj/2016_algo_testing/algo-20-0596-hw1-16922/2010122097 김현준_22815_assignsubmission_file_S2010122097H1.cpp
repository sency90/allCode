#include <stdio.h>
#pragma warning(disable:4996) 
int findb(int a[1000], int n, int bb, int b[1000]);
int finda(int b[1000], int n, int aa, int a[1000]);
void main()
{
	int n, a[1000] = { 0 }, b[1000] = { 0 };

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	int count = 0;
	int j = 0, tt = 9, t = 9;
	while (1)
	{
		if (count >= n)
			break;
		if (count == 0)
		{
			printf("%d ", b[j]);
			count++;
			j = b[0];
		}
		if (count >= n)
			break;
		tt = findb(a, n, j,b);
		count++;
		if (count >= n)
			break;
		if (tt != -1)
		{
			t = finda(b, n, tt, a);
			count++;
		}

		j = t;

		if (tt == -1)
		{
			break;
		}
	}
}
int findb(int a[1000], int n,int bb, int b[1000])
{
	for (int i = 0; i < n; i++)
	{
		if (bb == a[i] && bb != a[0])
		{
			if (a[i - 1] == b[0])
			{
				printf("%d ", a[0]);
				return a[n - 1];
			}
			printf("%d ", a[i - 1]);
			return a[i - 1];
		}
	}
	return -1;
}
int finda(int b[1000], int n, int aa, int a[1000])
{
	for (int i = 0; i < n; i++)
	{
		if (aa == b[i] && aa != b[0])
		{
			printf("%d ", b[i - 1]);
			return b[i - 1];
		}
	}
	//1
	return -1;
}
/*
7

1 2 4 5 3 6 7

4 5 2 6 7 3 1


4 2 5 1 6 3 7
*/