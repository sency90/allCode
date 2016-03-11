#include <stdio.h>
int tree[1000000];
int main() {
    int n, m, i, max=0;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) {
        scanf("%d", &tree[i]);
        if(tree[i] > max) max = tree[i];
    }
    int l=1, r=max, mid;
    long long sum, res=0;
    while(l<=r) {
        sum = 0;
        mid = (l+r)/2;
        for(i=0; i<n; i++) {
            if(tree[i]-mid > 0) {
                sum += tree[i] - mid;
            }
        }
        if(sum >= m) {
            if(res < mid) res = mid;
            l = mid+1;
        } else r = mid-1;
    }
    printf("%lld", res);
    return 0;
}
