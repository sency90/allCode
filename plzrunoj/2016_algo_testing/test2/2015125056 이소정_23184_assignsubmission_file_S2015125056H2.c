#include<iostream>
#include<stdio.h>
#pragma warning (disable:4996)


int main() {
	int num=0;
	int j;
	int i;
	int re;
	int k = 0;
	int count[1000] = {0};
	int temp[1000];
	int bigger[1000];
	scanf("%d", &num);
	if (num < 0 || num>1000)
	{
		printf("wrong");
		return 0;
	}
	for (i = 0; i < num; i++)
	{
		scanf("%d", &temp[i]);
	}
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (temp[j] >= temp[i]) {
				count[i]++;
			}
		}
		
	}

	for (i = 0; i < num; i++)
	{
		if (count[i] >= temp[i])
		{
			bigger[k] = temp[i];
			k++;
		}
	}
	re = 0;
	for (i = 0; i < k; i++)
	{
		if (bigger[re] <= bigger[i])
		{
			re = i;
		}
	}
	printf("%d", bigger[re]);
}