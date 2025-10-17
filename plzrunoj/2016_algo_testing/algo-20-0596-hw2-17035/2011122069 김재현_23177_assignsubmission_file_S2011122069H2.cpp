#include <cstdio>
#include <stdio.h>
#include <string.h>
using namespace std;

int dp[1002];

int main(){
	int arr[1001];
	int count, x, max, num;
	max = -1;
	memset(dp,0,sizeof(dp));

	scanf("%d",&num);

	for(int i=0; i<num;i++)
		scanf("%d",&arr[i]);

	for(int i=0; i<num; i++){
		x = arr[i];
		count = 0;

		if(!dp[x]){

			for(int k=0; k<num; k++){
				if(x <= arr[k])
					count++;
			}
		
			if(x == count){
				if(max < x)
					max = x;
			}

			dp[x]=1;
		}

	}

	if(max == -1)
		max = 0;

	printf("%d",max);

	return 0;
}


	