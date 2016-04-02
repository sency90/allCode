#include <stdio.h>
int main() {
    int x, y, sum=0, mx=0;
    for(int i=0; i<10; i++) {
        scanf("%d %d", &x, &y);
        sum-=x;
        if(mx < sum) mx = sum;
        sum+=y;
        if(mx < sum) mx = sum;
    }
    if(mx > 10000) puts("10000");
    else printf("%d", mx);
    return 0;
}
