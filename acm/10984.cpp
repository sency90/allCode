#include <stdio.h>
#include <cmath>
using namespace std;
int main() {
    int a, t, n, suma;
    double b, sumb;
    scanf("%d", &t);
    while(t--) {
        suma=0; sumb=0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d %lf", &a, &b);
            suma += a;
            sumb += a*b;
        }
        sumb/=suma;
        sumb = floor((sumb)*10+0.5)/10;
        printf("%d %.1f\n", suma, sumb);
    }
    return 0;
}
