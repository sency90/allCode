#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int sum=0;
    for(int i=0; i<=n; i+=2) {
        sum+=i;
    }
    printf("%d", sum);
    return 0;
}
