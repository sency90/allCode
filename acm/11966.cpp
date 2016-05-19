#include <stdio.h>
int main() {
    int n, isAns = 0;
    scanf("%d", &n);
    for(int i=0; i<=30; i++) {
        if(n==(1<<i)) {
            isAns = 1;
            break;
        } else if(n < (1<<i)) break;
    }
    printf("%d", isAns);
    return 0;
}
