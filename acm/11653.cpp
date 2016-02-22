#include <stdio.h>
int main() {
    int n, temp; scanf("%d", &n);
    temp = n;
    for(int j=2; j*j<=temp; j++) {
        while(n%j == 0) {
            printf("%d\n", j);
            n /= j;
        }
    }
    if(n!=1) printf("%d\n", n);
    return 0;
}
