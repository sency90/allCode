#include <stdio.h>
int main() {
    int d, a[6]={1,1,2,2,2,8};
    for(int i=0; i<6; i++) {
        scanf("%d", &d);
        printf("%d ", a[i]-d);
    }
    return 0;
}
