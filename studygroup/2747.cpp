#include <stdio.h>
int d[46];
int f(int x) {
    if(d[x]>0) return d[x];
    //base case
    if(x==0) return 0;
    if(x==1) return 1;
    //return f(x-1) + f(x-2);
    return d[x] = f(x-1) + f(x-2);
}
int main() {
    int x;
    scanf("%d", &x);
    printf("%d", f(x));
    return 0;
}
