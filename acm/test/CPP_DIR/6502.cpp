#include <stdio.h>
int main() {
    int r, w, l, i=0;
    while(true) {
        scanf("%d", &r);
        if(r==0) return 0;
        scanf("%d%d",&w,&l);
        if(w*w+l*l<=4*r*r) printf("Pizza %d fits on the table.\n", ++i);
        else printf("Pizza %d does not fit on the table.\n", ++i);
    }
    return 0;
}
