#include <stdio.h>
int main() {
    int n, d;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &d);
        printf("Pairs for %d:", d);
        for(int i=1; i*2<d; i++) {
            if(i==1) printf(" %d %d", i, d-i);
            else printf(", %d %d", i, d-i);
        } puts("");
    }
    return 0;
}
