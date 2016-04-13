#include <stdio.h>
#define RND 10007
int d[10][1001];
int f(int x, int n) {
    if(x<0 || x>=10) return 0;
    if(n==1) return 1;
    if(d[x][n] > 0) return d[x][n];

    int tmp=0;
    for(int i=0; i<=x; i++) {
        tmp = (tmp + f(i, n-1))%RND;
    }
    return d[x][n] = tmp;
}
int main() {
    int n, sum=0;
    scanf("%d", &n);
    for(int i=0; i<10; i++) {
        sum += f(i, n);
    }
    printf("%d", sum%RND);
    return 0;
}
