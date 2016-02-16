#include <stdio.h>
#define MAX(a,b) (a>b?a:b)
int main() {
    char x, max;
    double sum = 0;
    short n; scanf("%hd", &n);

    for(short i=0; i<n; i++) {
        scanf("%hhd", &x);
        max = MAX(max, x);
        sum += x;
    }
    sum = ((sum/n)*100)/max;
    printf("%.2lf\n", sum);
    return 0;
}
