#include <stdio.h>
int main() {
    int r, c, x=1, y=1, k, dir=0;
    scanf("%d %d %d", &r, &c, &k);
    if(k>r*c) {
        puts("0");
        return 0;
    }
    int ur=2, uc=1, i=1;
    while(k!=i) {
        if(dir==0) {
            if(y+1<=c) {
                y++; i++;
            } else {
                dir++;
                c--;
            }
        } else if(dir==1) {
            if(x+1<=r) {
                x++; i++;
            } else {
                dir++;
                r--;
            }
        } else if(dir==2) {
            if(y-1>=uc) {
                y--; i++;
            } else {
                dir++;
                uc++;
            }
        } else if(dir==3) {
            if(x-1>=ur) {
                x--; i++;
            } else {
                dir=0;
                ur++;
            }
        }
    }
    printf("%d %d", x, y);
    return 0;
}
