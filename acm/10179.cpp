#include <stdio.h>
#include <math.h>
int main() {
    int t; scanf("%d", &t);
    double a;
    while(t--) {
        scanf("%lf", &a);
        printf("$%.2lf\n", floor((a+0.005)*80)/100);
    }
    return 0;
}
