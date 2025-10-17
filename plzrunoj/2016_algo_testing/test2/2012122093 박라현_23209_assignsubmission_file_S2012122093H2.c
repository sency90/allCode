#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[1001];

int main()
{
	int n;
	scanf("%d",&n);
	

	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}

	sort(arr+0,arr+n);//o(logn)

	int max=0;

	for(int i=0; i<n; i++)//O(n)
	{
		if(n-i>=arr[i])
		{
			if(arr[i]>max)
			{
				max=arr[i];
			}
		}
	}

	printf("%d",max);
	return 0;
}