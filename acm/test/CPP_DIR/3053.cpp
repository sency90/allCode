#include <stdio.h>
#include <cmath>
using namespace std;
int main() {
    double pi = acos(-1);
    double r;
    scanf("%lf", &r);
    printf("%.6lf\n%.6lf\n", r*r*pi, r*r*2);
    return 0;
}
