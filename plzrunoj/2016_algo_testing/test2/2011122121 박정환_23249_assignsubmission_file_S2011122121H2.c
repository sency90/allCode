#include <stdio.h>
int a[1000];
int f(int num,int x){

	int count=0;
////////하나씩 검사해서 같거나 큰수가 있으면 카운트 증가///////
	for(int i=0;i<num;i++){
		if(a[i]>=x) count++;
	}
/////////////////////////////////////////////////////////////////
	if(x<=count) return x;//카운트보다 x가 같거나 작으면 x를 리턴
/////////////////////////////////////////////////////////////////
	return -1;
	
}

int main(){
	int n,big;
	for(int i=0;i<1000;i++){
		a[i]=-1;
	}

	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(int i=0;i<n;i++){
		////////x들중에서 가장 큰값을 추려내서 big에 저장.///////
		int k;
		k= f(n,a[i]);
		if(i==0){

		big = k;
		}
		else{
			if( k > big ){
				big= k;
			}
		}
		/////////////////////////////////////////////////////////
	}

	printf("%d",big);
}

	