#include <stdio.h>
int main() {
    int a, b, v[78498], k, j=0, l=0;
    bool isBreak;
    scanf("%d %d", &a, &b);
    for(int i=2; i<=b; i++) {
        if(1==i) continue;
        else if(2==i || 3==i) v[j++]=i;
        else {
            isBreak = false;
            for(l=0, k=v[l]+v[l]; v[l]*v[l]<=i; l++) {
                if(0 == i%v[l]) {
                    isBreak = true;
                    break;
                }
            }
            if(isBreak) continue;
            v[j++]=i;
        }
    }
    for(int i=0; i<j; i++) {
        if(v[i] >= a) printf("%d\n", v[i]);
    }
    return 0;
}
