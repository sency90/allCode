#include <stdio.h>
int main() {
    double x, y;
    scanf("%lf", &y);
    if((int)y == 999) return 0;
    while(true) {
        x = y;
        scanf("%lf", &y);
        if((int)y == 999) return 0;
        printf("%.2lf\n", y-x);
    }
    return 0;
}
