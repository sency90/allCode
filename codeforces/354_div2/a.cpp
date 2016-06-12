#include <stdio.h>
#include <cmath>
#include <cstdlib>
using namespace std;
int main() {
    int n, mx=0, mn=0x3f3f3f3f, mxidx, mnidx;
    int ans, d;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
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
    if(abs(mxidx-mnidx)==n-1) ans = n-1;
    else {
        if(mxidx>mnidx) {
            if(mxidx>n-1-mnidx) ans = mxidx;
            else ans = n-1-mnidx;
        } else {
            if(mnidx>n-1-mxidx) ans = mnidx;
            else ans = n-1-mxidx;
        }
    }
    printf("%d", ans);
    return 0;
}
