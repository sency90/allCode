#include <stdio.h>
#pragma warning(disable:4996) 

void main()
{
	int n, a[1000] = { -1 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int i = 0, temp = 0,result=-1, sresult=-1;
	while (a[i] != -1)
	{
		temp = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] >= a[i])
				temp++;
		}
		if (a[i] <= temp)
		{
			if(result<a[i])
				result = a[i];
		}
		i++;
	}
	if (result == -1)
	{
		printf("결과없음");
	}
	else
		printf("%d", result);
}