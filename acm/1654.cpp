#include <stdio.h>
long long lan[10000];
int main() {
    long long k, n, i, max=0;
    scanf("%lld %lld", &k, &n);
    for(i=0; i<k; i++) {
        scanf("%lld", &lan[i]);
        if(max < lan[i]) max = lan[i];
    }
    long long l=1, r=max, mid, sum, res=0;
    while(l<=r) {
        sum = 0;
        mid = (l+r)/2;
        for(i=0; i<k; i++) {
            sum += lan[i]/mid;
        }
        if(sum >= n) {
            if(res < mid) res = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    printf("%lld", res);
    return 0;
}
