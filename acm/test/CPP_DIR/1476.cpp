#include <stdio.h>
int main() {
    int e, s, m, i;
    scanf("%d %d %d", &e, &s, &m);
    int a=0, b=0, c=0;
    for(i=1; i<1000000; i++) {
        a=a%15+1;
        b=b%28+1;
        c=c%19+1;
        if(e==a && s==b && m==c) break;
    }
    printf("%d", i);
    return 0;
}
