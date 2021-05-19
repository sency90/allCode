#include <stdio.h>
#include <algorithm>
int v[10000];
int main() {
    int n, j=0;
    long long sum=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    std::sort(v,v+n);
    for(int i=n-1; v[j]<v[i]; i--, j++) {
        sum+=(long long)(v[i]-v[j])*(n-(2*j+1));
    }
    printf("%lld", sum*2);
    return 0;
}
