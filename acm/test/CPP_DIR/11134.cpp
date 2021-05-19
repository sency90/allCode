#include <stdio.h>
int main() {
    int t; scanf("%d", &t);
    int n, c;
    while(t--) {
        scanf("%d %d", &n, &c);
        if(n%c==0) printf("%d\n", n/c);
        else printf("%d\n", n/c+1);
    }
    return 0;
}
