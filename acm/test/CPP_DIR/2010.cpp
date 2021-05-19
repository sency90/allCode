#include <stdio.h>
int main() {
    int n, sum = 0;
    short x[500000];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%hd", &x[i]);
        sum += x[i];
    }
    printf("%d\n", sum-n+1);

    return 0;
}
