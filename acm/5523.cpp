#include <stdio.h>
int main() {
    int n, a, b, ca=0, cb=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        if(a>b) ca++;
        else if(a<b) cb++;
    }
    printf("%d %d", ca, cb);
    return 0;
}
