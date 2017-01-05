#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b);
int main(){
	int num;
	scanf("%d",&num);
	int i;
	int Arr[11];
	int j;
	for(j=0;j<num;j++){
		for(i=0;i<10;i++){
			scanf("%d",&Arr[i]);
		}
		qsort(Arr,10,sizeof(int),compare);
        printf("%d\n", Arr[2]);
	}
	return 0;
}

int compare(const void* a, const void* b){
    if( *(int*)a > *(int*)b ) return -1;
    if( *(int*)a < *(int*)b ) return 1;
    return 0;
}
