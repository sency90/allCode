#include <stdio.h>
int main() {
    int asc[1000], dsc[1000], a[1000];
    int i, j, n, amax, dmax, rMax = 1;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
        asc[i] = 1;
        dsc[i] = 1;
        amax = 0;

        for(j=0; j<i; j++) {
            if(a[j] < a[i]) {
                if(amax < asc[j]) amax = asc[j];
            }
        }
        asc[i] = amax+1;
    }
    rMax = 1;
    for(i=n-1; i>=0; i--) {
        dmax = 0;
        for(j=n-1; j>i; j--) {
            if(a[j] < a[i]) {
                if(dmax < dsc[j]) dmax = dsc[j];
            }
        }
        dsc[i] = dmax+1;
        if(rMax < asc[i]+dsc[i]) rMax = asc[i]+dsc[i];
    }
    printf("%d", rMax-1);
    return 0;
}
