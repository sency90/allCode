#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int arr[10001], n, Max;
	int flag = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > n - i - 1)
		{
			printf("%d", n - i);
			return 0;
		}
	}

	printf("0");

	return 0;
}
