#include <stdio.h>
int main() {
    int t, sum, d, mn;
    scanf("%d", &t);
    while(t--) {
        sum = 0;
        mn = 10000;
        for(int i=0; i<7; i++) {
            scanf("%d", &d);
            if(d%2==0) {
                if(mn > d) mn = d;
                sum += d;
            }
        }
        printf("%d %d\n", sum, mn);
    }
    return 0;
}
