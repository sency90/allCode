
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void main()
{


	int i = 0, j, s=0, k;
	int num[10000], num2[10000];
	int temp,max;
	
	cin >> k;
	
	for (int i = 0; i<k; i++) scanf_s("%d", &num[i]);
	
	
	for (i = 0; i < k; i++)
	{
		for (j = i; j < k; j++)
		{
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	
	

	for (i = 0; i < k; i++){
		if (num[i] > 0){
			if (k - i - 1 >= num[i]){
				num2[s] = num[i];
				s++;
			}
		}
	}
	max = num2[s];
	for (s = 0; s < k; s++){
		
		if (max < num2[s + 1])
			max = num2[s+1];
			

	}
	cout << "´ä";
	cout << max << " ";
	system("pause");

}