#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    n*=2;
    int lo=0, hi=1000;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(mid*(mid+1)<n) lo = mid+1;
        else hi = mid-1;
    }
    printf("%d", hi+1);
    return 0;
}
