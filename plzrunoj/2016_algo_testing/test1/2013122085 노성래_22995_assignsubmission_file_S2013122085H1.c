#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void in(int center, int size, int *pre, int *post)
{
	int *left, *right;
	int i = 0;
	while (i < size)
	{
		if (post[i] == center)
		{
			i++;
			break;
		}
		i++;
	}
	left = new int[i];
	right = new int[i];
	int j = 0;
	while (j < i)
	{
		left[j] = pre[j + 1];
		right[j] = post[j];
		j++;
	}
	if (j == 1)	cout << left[0] << " ";
	else in(left[1], i, left, right);
	cout << pre[0] << " ";
	if ((size - i - 1) == 0) return;
	left = new int[size - i - 1];
	right = new int[size - i - 1];
	int temp = i;
	while (i < size - 1)
	{
		left[i - temp] = pre[i + 1];
		right[i - temp] = post[i];
		i++;
	}
	if (i == temp + 1) cout << left[0] << " ";
	else in(left[1], size - temp - 1, left, right);
}
int main()
{
	int size = 0;
	int *pre, *post;
	int i = 0, j = 0;


	scanf_s("%d", &size);


	pre = new int[size];
	post = new int[size];

	while (i<size)
	{
		scanf_s("%d", &pre[i++]);
	}

	i = 0;
	while (i < size)
	{
		scanf_s("%d", &post[i++]);
	}

	in(pre[1], size, pre, post);

	return 0;
}