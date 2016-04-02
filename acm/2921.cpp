#include <stdio.h>
int main() {
    int a=0, n;
    scanf("%d", &n);
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=i; j++) {
            a += i+j;
        }
    }
    printf("%d", a);
}
