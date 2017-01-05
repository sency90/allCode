#include <cstdio>
using namespace std;
#pragma warning (disable : 4996)

int array[101][101][101] = { 0, };

int find(int num, int left, int right)
{
	array[1][1][1] = 1;

	if (array[num][left][right] == 0)
	{
		if (num > 1)
		{
			array[num][left][right] = (num - 2) * find(num - 1, left, right) + find(num - 1, left - 1, right) + find(num - 1, left, right - 1);
		}
		else if (num <= 1)
		{
			return array[num][left][right];
		}
	}
	else
	{
		return array[num][left][right];
	}

	//array[num][left][right] = (num - 2) * array[num - 1][left][right] + array[num - 1][left - 1][right] + array[num - 1][left][right - 1];

	return array[num][left][right];
}

int main()
{
	int num;
	int left;
	int right;
	int answer = 0;

	scanf("%d%d%d", &num, &left, &right);

	answer = find(num, left, right);

	printf("%d", answer);

	return 0;
}
