#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,c,c1=0,c2=0,a,max=0;
	int *x,*x1,*x2;
	scanf("%d",&n);
	x = (int*)malloc(sizeof(int)*n);//입력 값들 저장
	x1 = (int*)malloc(sizeof(int)*n);//입력 수들 조건비교 후 값들 저장
	x2 = (int*)malloc(sizeof(int)*n);//조건을 만족하는 값들 저장

	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);//8 4 5 3 10
	}
	for(i=0;i<n;i++)//비교
	{
		c=0;
		for(j=0;j<n;j++)
		{
			if(x[i]<=x[j])
			{
				c++;
			}
			x1[i]=c;
		}
	}
	/*
	for(i=0;i<n;i++)
	{
		printf("%d ",x1[i]);//2 4 3 5 1
	}
	*/
	for(i=0;i<n;i++)//조건에 맞는 값들 구하기
	{
		if(x[i]<=x1[i])
		{
			a=x[i];
			x2[c1]=a;
			a=0;
			c1++;
		
		}
	}
	
	//printf("조건을 만족하는 수의 갯수 %d",c1);
	for(j=0;j<c1;j++){
		//printf("그래서 나온 값들 %d",x2[j]);
	if(x2[j]>max)
		max=x2[j];
	}
	printf("%d ",max);
	
}