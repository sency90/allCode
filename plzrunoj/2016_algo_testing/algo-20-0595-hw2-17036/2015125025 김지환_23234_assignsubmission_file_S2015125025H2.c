#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
int main(void)
{
	int num=0;
	char* result;
	char arr_char[1000];//�Է��� ���� ���ڿ�
	char arr_char_ex[1000];
	int arr_int[1000];//�и��Ǽ� intȭ�� �迭
	int i = 0;
	int j = 0;
	int count = 0;	 
	int arr_count[1000]; 
	int arr_result[1000];
	int max = arr_result[0];
	scanf("%d", &num);
	scanf("%s", arr_char);
	
	result = strtok(arr_char, " ");//���ڿ��� ��������� �и�
	while (result != NULL)
	{
		arr_char_ex[i] = result;
		i++;
	}
	for (i = 0; i < num; i++)	 //integer parsing
	{
		arr_int[i] = atoi(arr_char_ex[i]);
	}
	
	for (int j = 0; j < num ; j++)
	{
		for (int i = 0; i < num;  i++)
		{
			if (arr_int[i] >= arr_int[j])
				count++;
		}
		arr_count[j] = count;
	}
	
	for (int i = 0; i < num; i++)
	{
		if (arr_count[i] >= arr_int[i])
			arr_result[i] = arr_int[i];
		else
			arr_result[i] = 0;			
	}
	for (int i = 0; i < num; i++)
	{		
		if (arr_result[i] > max)
			max = arr_result[i];
	}
	printf("%d", max);
}