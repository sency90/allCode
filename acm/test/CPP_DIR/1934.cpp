#include <stdio.h>
int x, y, temp;
int i;
int main() {

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &x, &y);
        if(x > y) {
            temp = x;
            x = y;
            y = temp;
        }

        for(i=x; i>=1; i--) {
            if((x % i) == 0) {
                if((y % i)  == 0) {
                    printf("%d\n", (x*y)/i);
                    break;
                }
            }
        }
    }

    return 0;
}
