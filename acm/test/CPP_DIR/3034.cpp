#include <stdio.h>
int main() {
    int n, w, h, d;
    scanf("%d %d %d", &n,&w,&h);
    int lim = w*w+h*h;
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        if(d*d <= lim) puts("DA");
        else puts("NE");
    }
    return 0;
}
