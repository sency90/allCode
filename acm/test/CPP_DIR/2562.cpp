#include <stdio.h>
int main() {
    int d, mx=0, i=0, idx;
    while(scanf("%d", &d)!=EOF) {
        i++;
        if(mx < d) {
            mx = d;
            idx = i;
        }
    }
    printf("%d\n%d", mx, idx);
    return 0;
}
