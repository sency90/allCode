#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int d[10001][4], v[10001];
int f(int n, int p) {
    if(n == 0) return 0;
    if(n == 1) {
        if(p % 2 == 0) return 0;
        else return v[1];
    }
    if(d[n][p] > 0) return d[n][p];

    switch(p) {
        case 0:
            d[n][p] = f(n-1,2);
            break;
        case 1:
            d[n][p] = max(f(n-1,0), f(n-1,2)) + v[n];
            break;
        case 2:
            d[n][p] = max(f(n-1,1), f(n-1,3));
            break;
        case 3:
            d[n][p] = f(n-1,1) + v[n];
            break;
    }
    return d[n][p];
}
int main() {
    memset(d, 0, sizeof(d));
    int n, max = 0, temp;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i=0; i<4; i++) {
        temp = f(n,i);
        if(max < temp) max = temp;
    }
    printf("%d", max);
    return 0;
}
