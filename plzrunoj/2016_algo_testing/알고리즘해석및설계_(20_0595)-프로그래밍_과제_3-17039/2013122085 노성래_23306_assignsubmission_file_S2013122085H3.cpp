#include <cstdio>
#include <iostream>
using namespace std;
int toprint = 0;

int building(int *arr, int size, bool direction)
{
	int temp, i, count = 1;
	if (direction)
	{
		temp = arr[0]; i = 0;
		while (i < size)
		{
			if (temp < arr[i])
			{
				temp = arr[i]; count++;
			}
			i++;
		}
	}
	else
	{
		temp = arr[size - 1]; i = size - 1;
		while (i>-1)
		{
			if (temp < arr[i])
			{
				temp = arr[i]; count++;
			}
			i--;
		}
	}
	return count;
}

void soonyul(int *arr, int current, int *size)
{
	if (current == size[0] - 1)
	{
		if (building(arr, size[0], true) == size[1])
		{
			if (building(arr, size[0], false) == size[2])
			{
				toprint++;
			}
		}
	}
	else
	{
		int i = current;
		int temp = 0;
		while (i < size[0])
		{
			temp = arr[i];
			arr[i] = arr[current];
			arr[current] = temp;

			soonyul(arr, current + 1, size);

			temp = arr[i];
			arr[i++] = arr[current];
			arr[current] = temp;
		}
	}
}

int main()
{
	int *num;
	int *arr;
	int i = 0;

	num = new int[3];


	scanf_s("%d%d%d", &num[0], &num[1], &num[2]);

	arr = new int[num[0]];
	i = 0;
	while (i<num[0])
	{
		arr[i] = i + 1;
		i++;
	}

	soonyul(arr, 0, num);

	cout << toprint % 1000000007 << endl;
	return 0;
}