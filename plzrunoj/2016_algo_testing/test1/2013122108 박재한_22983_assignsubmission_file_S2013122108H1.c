#include <iostream>
#include <cstdio>
using namespace std;
#pragma warning (disable:4996)

void recFind(int *front, int *back, int *middle, int remainNode, int frontIndex, int backIndex, int middleIndex);
int indexOf(int num, int *arr, int remainNode, int startIndex);

void findMiddle(int *front, int *back, int *middle, int numOfNode)
{
	recFind(front, back, middle, numOfNode, 0, 0, 0);
}

void recFind(int *front, int *back, int *middle, int remainNode, int frontIndex, int backIndex, int middleIndex)
{
	if (remainNode > 1)
	{
		int index = indexOf(front[frontIndex + 1], back, remainNode, backIndex);
		int numOfLeft = index - backIndex + 1;

		middle[middleIndex + numOfLeft] = front[frontIndex];
		recFind(front, back, middle, numOfLeft, frontIndex + 1, backIndex, middleIndex);
		recFind(front, back, middle, remainNode - numOfLeft - 1, frontIndex + numOfLeft + 1, backIndex + numOfLeft, middleIndex + numOfLeft + 1);
	}
	else if (remainNode == 1)
	{
		middle[middleIndex] = front[frontIndex];
	}

	return;
}

int indexOf(int num, int *back, int remainNode, int backIndex)
{
	for (int i = 0; i < remainNode; i++)
	{
		if (back[i + backIndex] == num)
		{
			return i + backIndex;
		}
	}
}

int main()
{
	int numOfNode = 0;

	scanf("%d", &numOfNode);

	int *front = new int[numOfNode];
	int *back = new int[numOfNode];
	int *middle = new int[numOfNode];

	for (int i = 0; i < numOfNode; i++)
	{
		scanf("%d", &front[i]);
	}

	for (int i = 0; i < numOfNode; i++)
	{
		scanf("%d", &back[i]);
	}

	findMiddle(front, back, middle, numOfNode);

	for (int i = 0; i < numOfNode; i++)
	{
		printf("%d ", middle[i]);
	}
	printf("\b");

	delete[] front;
	delete[] back;
	delete[] middle;
	
	return 0;
}