#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;

int main(){
	scanf("%d", &n);
	
	int numArray[n];
	int cntArray[n];
	int max=0;
	
	memset(numArray,0,sizeof(numArray));
	memset(cntArray,0,sizeof(cntArray));
	
	
	
	for(int i=0; i<n; i++){
		scanf("%d",&numArray[i]);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(numArray[j] >= numArray[i]){
				cntArray[i]++;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		if(cntArray[i] >= numArray[i]){
			if(numArray[i] > max){
				max = numArray[i];
			}
		}
	}

	printf("%d\n",max);
	
}
