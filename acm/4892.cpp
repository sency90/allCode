#include <stdio.h>
int main() {
    int n[5], i=0;
    bool isn1even;
    while(true) {
        scanf("%d", &n[0]);
        if(n[0] == 0) return 0;
        n[1] = n[0]*3;
        if(n[1]%2 == 0) {
            isn1even = true;
            n[2] = n[1]/2*3/9;
        } else {
            isn1even = false;
            n[2] = (n[1]+1)/2*3/9;
        }
        if(isn1even) {
            printf("%d. even %d\n", ++i, n[2]);
        } else {
            printf("%d. odd %d\n", ++i, n[2]);
        }
    }
    return 0;
}
