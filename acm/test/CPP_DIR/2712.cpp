#include <stdio.h>
#include <string.h>
int main() {
    int t; scanf("%d", &t);
    while(t--) {
        char u[3];
        double d;
        scanf("%lf %s", &d, u);

        if(!strcmp(u, "kg")) printf("%.4lf lb\n", d*2.2046);
        else if(!strcmp(u, "lb")) printf("%.4lf kg\n", d*0.4536);
        else if(!strcmp(u, "l")) printf("%.4lf g\n", d*0.2642);
        else printf("%.4lf l\n", d*3.7854);

    }
    return 0;
}
