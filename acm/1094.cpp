#include <stdio.h>
int main() {
    int n, x=0;
    scanf("%d", &n);
    while(n!=0) {
        if(n%2) x++;
        n/=2;
    }
    printf("%d", x);
    return 0;
}
