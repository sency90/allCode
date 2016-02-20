#include <stdio.h>
#include <string.h>
#define RND 1000000000
int d[201][201];
int f(int n, int k) {
    if(d[n][k] > 0) return d[n][k];
    else if(k==1) return d[n][k] = 1;
    else if(k==2) return d[n][k] = n+1;
    long long temp = 0;
    for(int j=0; j<=n; j++) temp += f(n-j, k-1);
    return d[n][k] = temp % RND;
}
int main() {
    memset(d, 0, sizeof(d));
    int n, k; scanf("%d %d", &n, &k);
    printf("%d", f(n, k));
    return 0;
}
