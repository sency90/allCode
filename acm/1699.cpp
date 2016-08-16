#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <limits.h>
#define power(a) (a*a)
using namespace std;
char d[100001];
char f(int x) {
    if(d[x] > 0) return d[x];
    if(x == 0) return d[x] = 0;
    if(x == 1) return d[x] = 1;
    char temp, min = CHAR_MAX;
    for(int j=1; power(j)<=x; j++) {
        temp = f(x-power(j));
        if(min > temp) min = temp;
    }
    return d[x] = min + 1;
}
int main() {
#ifdef PLZRUN
    freopen("input", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(d, 0, sizeof(d));
    int n; scanf("%d", &n);
    printf("%hhd", f(n));
    return 0;
}
