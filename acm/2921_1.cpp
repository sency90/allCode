#include <stdio.h>
int n, cnt=0;
int main() {
    scanf("%d", &n);
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=i; j++) {
            cnt += i+j;
        }
    }
    printf("%d", cnt);
    return 0;
}
