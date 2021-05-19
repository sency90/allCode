#include <stdio.h>
int main() {
    int a=0, b=0;
    int d, n; scanf("%d", &n);
    while(n--) {
        scanf("%d", &d);
        if(d==1) a++;
        else b++;
    }
    printf("Junhee is ");
    if(a>b) printf("cute!");
    else printf("not cute!");
}
