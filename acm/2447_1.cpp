#include <stdio.h>
int n, k=1, cnt=0;
int f(int x) {
    if(0 == x) return printf(" ");
    if(1 == x) return printf("*");
    for(int i=0; i<3; i++) f(x-1);
    printf("\n");
    f(x-1);
    //for(int i=0; i<n/3; i++) f(0);
    f(0);
    f(x-1);
    printf("\n");
    for(int i=0; i<3; i++) f(x-1);
    printf("\n");
    return 0;
}
int main() {
    scanf("%d", &n);
    while(true) {
        cnt++;
        if(n == k) break;
        k *= 3;
    }
    f(cnt);
    return 0;
}
