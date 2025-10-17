#include<stdio.h>

int main(){
	int *ary, *ary2;
	int num, num2 = 0, count;

	scanf("%d", &num);
	ary = (int*)malloc(sizeof(int)*num);//메모리 낭비 최소화
	ary2 = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++){
		scanf("%d", &ary[i]);
	}
	for (int i = 0; i < num; i++){//자기보다 크거나 같은 것의 갯수가 자기 자신보다 크거나 같은 수를 저장
		count = 0;
		for (int j = 0; j < num; j++){
			if (ary[i] <= ary[j]){
				count++;
			}
		}
		if (count >= ary[i]){
			ary2[num2++] = ary[i];
		}
	}
	count = ary2[0];
	for (int i = 0; i < num2; i++){
		if (ary2[i] > count) count = ary2[i];
	}
	printf("%d\n", count);
	return 0;
}