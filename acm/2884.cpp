#include <stdio.h>
int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    x+=23; y+=15;
    if(y>=60) {
        y-=60;
        x+=1;
    }
    if(x>=24) {
        x-=24;
    }
    printf("%d %d", x, y);
    return 0;
}
