#include <stdio.h>
int n,k,v,w,d[100001];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&w,&v);
        for(int j=k; j>=w; j--) if(d[j-w]+v > d[j]) d[j]=d[j-w]+v;
    }
    printf("%d", d[k]);
    return 0;
}
