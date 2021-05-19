#include <stdio.h>
int main() {
    int n, a=0;
    scanf("%d", &n);
    while(n!=0) a+=n=n/5;
    printf("%d",a);
}
