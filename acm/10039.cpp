#include <stdio.h>
int main() {
    int d, sum=0;
    for(int i=0; i<5; i++) {
        scanf("%d", &d);
        if(d<40) d = 40;
        sum += d;
    }
    printf("%d", sum/5);
}
