#include <stdio.h>

int main() {

    int x; scanf("%d", &x);
    int i = 1;
    for(; i*i <= x; i++) {
        if(x%i == 0) {
            printf("%d ", i);
            if(x/i!=i) printf("%d ", x/i);
        }
    }
    printf("\n");
    return 0;
}
