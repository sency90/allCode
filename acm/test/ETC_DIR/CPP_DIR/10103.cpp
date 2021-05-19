#include <stdio.h>
int main() {
    int n, sa=100, sb=100, a, b;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &a, &b);
        if(a<b) sa-=b;
        else if(b<a) sb-=a;
    }
    printf("%d\n%d\n",sa,sb);
}
