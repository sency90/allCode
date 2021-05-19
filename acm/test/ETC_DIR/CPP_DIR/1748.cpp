#include <stdio.h>
int main() {
    int n,t,i,j=1,c=0,s=0;
    scanf("%d",&n); t=n;
    while(n/=10)c++;
    for(i=1;i<=c;i++,j*=10)s+=9*j*i;
    s+=(t+1-j)*i;
    printf("%d",s);
}
