#include <stdio.h>
int main() {
    int m, pos=1, x, y;
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        if(x==pos) pos=y;
        else if(y==pos) pos=x;
    }
    printf("%d", pos);
    return 0;
}
