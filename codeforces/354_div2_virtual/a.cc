#include <stdio.h>
#include <algorithm>
using namespace std;
int d, mx=0, mn=0x3f3f3f3f, mxidx, mnidx;
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &d);
        if(mx<d) {
            mx=d;
            mxidx=i;
        }
        if(mn>d) {
            mn=d;
            mnidx=i;
        }
    }
    printf("%d", max({mxidx-1, mnidx-1, n-mxidx, n-mnidx}));
    return 0;
}
