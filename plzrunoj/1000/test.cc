#include <stdio.h>
#include <string.h>
int main(){
	int j,i,N,c=0;
	int b[123],score;
	for(i=0;i<123;i++)
		b[i]=0;
	char a[101];
	scanf("%d",&N);
	score=N;
	for(i=0;i<N;i++){
        memset(b,0,sizeof(b));
		scanf("%s",a);
        c=0;
		while(a[c]!=0)
			c++;
		for(j=0;j<=c;j++){
			if(b[a[j]]==0){
				b[a[j]]++;
			}
			else if(b[a[j]]!=0 && a[j]!=a[j-1]){
				--score;
				break;
			}
		}
	}
	printf("%d",score);
}
