#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int size = 0, i = 0, j = 0, temp = 0, tempcount = 0, current=-1;
	int *num;
	scanf_s("%d", &size);

	num = new int[size];
	
	while (i<size)
	{
		scanf_s("%d", &num[i++]);
	}

	i = 0;
	while (i<size)
	{
		j = 0; temp = num[i];
		tempcount = 0;
		while (j<size)
		{
			if (temp <= num[j]) tempcount++;
			j++;
		}
		if (temp <= tempcount)
		{
			if(current<temp) current = temp;
		}
		i++;
	}
	cout << current << endl;

	return 0;
}