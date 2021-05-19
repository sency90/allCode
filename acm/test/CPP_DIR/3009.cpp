#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int a, b, x[3], y[3];
    for(int i=0; i<3; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    sort(x, x+3);
    sort(y, y+3);

    if(x[0]==x[1]) a = x[2];
    else a = x[0];
    if(y[0]==y[1]) b = y[2];
    else b = y[0];
    printf("%d %d", a, b);
}
