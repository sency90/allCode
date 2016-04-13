#include <stdio.h>
int main() {
    int a, b, mx=0, cnt=0;
    for(int i=0; i<4; i++) {
        scanf("%d %d", &a, &b);
        cnt -= a;
        cnt += b;
        if(mx < cnt) mx = cnt;
    }
    printf("%d", mx);
    return 0;
}
