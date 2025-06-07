#include <cstdio>
using namespace std;
#pragma warning (disable:4996)


int main()
{
	int n;
	int *array;
	int *check;
	int large[2];

	scanf("%d", &n);

	array = new int[n];
	check = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	large[0] = -1;
	large[1] = -1;

	for (int i = 0; i < n; i++)
	{
		check[i] = 0;

		for (int j = 0; j < n; j++)
		{
			if (array[i] <= array[j])
			{
				check[i]++;
			}
		}

		if ((array[i] <= check[i]) && (large[0] <= check[i]) && (large[1] < array[i]))
		{
			large[0] = check[i];
			large[1] = array[i];
		}

	}

	printf("%d", large[1]);

	delete[] array;
	delete[] check;

	return 0;
}