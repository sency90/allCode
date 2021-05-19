#include <stdio.h>
#include <cmath>
using namespace std;
int main() {
    double a, b;
    while(scanf("%lf %lf",&a, &b)!=EOF) {
        printf("%.2lf\n", a/b);
    }
    return 0;
}
