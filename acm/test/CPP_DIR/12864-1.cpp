#include <stdio.h>
float v[5000];
short w[5000];
int d[5000];
int main() {
    int n, sum=0, mx=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%f", &v[i]);
    for(int i=0; i<n; i++) {
        scanf("%hd", &w[i]);
        sum += w[i];
        d[i]=w[i];
    }
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
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
