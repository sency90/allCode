#include <stdio.h>
int main() {
    int a, b, cnt=0, mx=0;
    for(int i=0; i<10; i++) {
        scanf("%d %d", &a, &b);
        cnt -= a;
        cnt += b;
        if(mx < cnt) mx = cnt;
    }
    printf("%d", mx);
    return 0;
}
