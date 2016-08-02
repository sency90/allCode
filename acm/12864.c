#include <stdio.h>
int main() {
    float v[5000];
    int w[5000],d[5000],n,sum=0,mx=0,i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%f", &v[i]);
    for(i=0; i<n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
        d[i]=w[i];
    }
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(v[i]<=v[j]) {
                if(d[j]<d[i]+w[j]) {
                    d[j]=d[i]+w[j];
                    if(mx<d[j]) mx=d[j];
                }
            }
        }
    }
    printf("%d", sum-mx);
    return 0;
}
