#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,c,c1=0,c2=0,a,max=0;
	int *x,*x1,*x2;
	scanf("%d",&n);
	x = (int*)malloc(sizeof(int)*n);//�Է� ���� ����
	x1 = (int*)malloc(sizeof(int)*n);//�Է� ���� ���Ǻ� �� ���� ����
	x2 = (int*)malloc(sizeof(int)*n);//������ �����ϴ� ���� ����

	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);//8 4 5 3 10
	}
	for(i=0;i<n;i++)//��
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
	for(i=0;i<n;i++)//���ǿ� �´� ���� ���ϱ�
	{
		if(x[i]<=x1[i])
		{
			a=x[i];
			x2[c1]=a;
			a=0;
			c1++;
		
		}
	}
	
	//printf("������ �����ϴ� ���� ���� %d",c1);
	for(j=0;j<c1;j++){
		//printf("�׷��� ���� ���� %d",x2[j]);
	if(x2[j]>max)
		max=x2[j];
	}
	printf("%d ",max);
	
}