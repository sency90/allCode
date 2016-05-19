#include <stdio.h>
int a[100001];
int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", a+i);
    }

    long long i;
    for(i=0;;i++) {
        if(k < (i*i-i+2)/2) break;
    }
    i--;
    int j = k-(i*i-i+2)/2;
    printf("%d", a[j]);
    return 0;
}
