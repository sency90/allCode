#include <stdio.h>
#include <algorithm>
using namespace std;
int d[1001], a[1001], mx=1;
int f(int x) {
    if(x==1) return 1;
    if(d[x]>0) return d[x];
    int pmx = 0;
    for(int i=x-1; i>=1; i--) {
        if(a[x] > a[i]) {
            pmx = max(pmx, f(i));
        } else f(i);
    }
    d[x] = pmx+1;
    mx = max(mx, d[x]);
    return d[x];
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", a+i);
    }
    f(n);
    printf("%d", mx);
    return 0;
}
