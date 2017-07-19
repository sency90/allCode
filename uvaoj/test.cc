#include <stdio.h>
int main() {
    double d, a=30000.0, b;
    b=a;
    for(int i=0; i<49; i++) {
        if(i==0) d=0.2;
        else if(i==1) d=0.05;
        else if(i==12) d=0.025;
        a-=2400.0;
        b*=(1.0-d);
    }
    printf("%lf %lf\n",a,b);
    return 0;
}
