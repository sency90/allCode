#include <stdio.h>
int main() {
    int a[10], d, ca=0, cb=0;
    for(int i=0; i<10; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<10; i++) {
        scanf("%d", &d);
        if(d == a[i]) continue;
        else if(d < a[i]) ca++;
        else cb++;
    }
    if(ca > cb) printf("A");
    else if(ca < cb) printf("B");
    else printf("D");
    return 0;
}
