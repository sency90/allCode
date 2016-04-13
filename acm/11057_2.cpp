#include <stdio.h>
#define RND 1000000000
unsigned int d[10][101];
unsigned int f(int x, int n) {
    if(x<0 || x>=10) return 0;
    if(n==1) {
        if(x==0) return 0;
        else return 1;
    }
    if(d[x][n] > 0) return d[x][n];
    return d[x][n] = (f(x-1, n-1) + f(x+1, n-1))%RND;
}
int main() {
    int n, sum=0;
    scanf("%d", &n);
    for(int i=0; i<10; i++) {
        sum = (sum + f(i, n))%RND;
    }
    printf("%u", sum);
    return 0;
}
