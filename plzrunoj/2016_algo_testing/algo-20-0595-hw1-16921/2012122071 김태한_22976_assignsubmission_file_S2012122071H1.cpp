#include <stdio.h>

int arr1[1000] = { 0 };
int arr2[1000] = { 0 };
int cor[1000] = { 0 };
int left[1000] = { 0 };
int right[1000] = { 0 };
int compare[1000] = { 0 };
int compare2[1000] = { 0 };
int temp = 0;
int r = 0;
int L_size = 0;
int R_size = 0;


void Left(int *left, int *compare, int L_size);
void Right(int *right, int *compare, int R_size);

void main()
{
	int a = 0;
	scanf("%d", &a);
	int b = 0;

	for (int i = 0; i < a; i++)
	{
		scanf("%d", &b);
		arr1[i] = b;
	}

	for (int i = 0; i < a; i++)
	{
		scanf("%d", &b);
		arr2[i] = b;
	}
	
	if (a == 1) 
	{
		printf("%d\n", arr1[0]);
		return;
	}
		
	for (int i = 0; i < a; i++)
	{
		
		if (arr2[a - 2] == arr1[i])
		{
			cor[i-1] = arr2[a - 1];
			temp = i;
			for (int k = 0; k < i - 1; k++)
			{
				left[k] = arr1[k + 1];
				L_size++;
			}
			break;
		}
	}
	for (int k = 0; temp < a; temp++, k++)
	{
		right[k] = arr1[temp];
		R_size++;
	}
	for (int i = 0; i < L_size; i++)
		compare[i] = arr2[i];
	for (int k = L_size; k < a - 1; k++, r++)
		compare2[r] = arr2[k];
	
	
	Left(left, compare, L_size);
	Right(right, compare2, R_size);
	
	for (int i = 0; i < L_size; i++)
		printf("%d ", left[i]);
	printf("%d ", cor[L_size]);
	for (int i = 0; i < R_size; i++)
		printf("%d ", right[i]);
	printf("\n");
}

void Left(int *left, int *compare, int L_size)
{
	int a = 0;
	int temp = 0;
	int i = 0;
	int r=1;
	if (L_size == 1 || L_size == 2)
		return;
	
		
	else if (L_size == 3)
	{
		if (compare[L_size - 2] == left[1])
			return;
		else
		{
			temp = left[0];
			left[0] = compare[0];
			left[1] = temp;
			return;
		}
	}
	else {
		for (i = 1; i < L_size; i++)
		{
			a++;
			if (compare[L_size - 2] == left[i])
			{
				temp = left[0];
				for (int k = 0; k < i - 1; k++)
					left[k] = left[k + 1];
				left[i - 1] = temp;
				break;
			}
		}
	}
	r = L_size - a - 1;
	Left(left, compare, a-1);
	if ((L_size - a - 1) == 0)
		r = 1;
	Left(&left[i], &compare[i-1],r);

}

void Right(int *right, int *compare, int R_size)
{
	int a = 0;
	int temp = 0;
	int i = 0;
	int r = 1;
	if (R_size == 1 || R_size == 2)
		return;
	
	else if (R_size == 3)
	{
		if (compare[R_size - 2] == right[1])
			return;
		else
		{
			temp = right[0];
			right[0] = compare[0];
			right[1] = temp;
			return;
		}
	}

	else {
		for (i = 1; i < R_size; i++)
		{
			a++;
			if (compare[R_size - 2] == right[i])
			{
				temp = right[0];
				for (int k = 0; k < i - 1; k++)
					right[k] = right[k + 1];
				right[i - 1] = temp;
				break;
			}
		}
	}
	r = R_size - a - 1;
	Right(right, compare, a - 1);
	if (r == 0)
		r = 1;
	Right(&right[i], &compare[i - 1], r);
}