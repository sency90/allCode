#include <stdio.h>
#define FOR(i, E) for(int i=0; i<(E); i++)
#define NEWINT(x) int x; scanf("%d", &x)

int main() {

    NEWINT(x);
    FOR(i, x) {
        FOR(j, i+1) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
