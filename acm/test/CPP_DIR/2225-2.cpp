#include <stdio.h>
#define RND 1000000000
int d[201][201];
int f(int x, int k) {
    if(k==1) return 1;
    if(d[x][k] > 0) return d[x][k];
    for(int i=0; i<=x; i++) {
        d[x][k] = (d[x][k] + f(x-i,k-1))%RND;
    }
    return d[x][k];
}
int main() {
    int n, k;
    scanf("%d%d", &n,&k);
    printf("%d", f(n,k));
    return 0;
}
