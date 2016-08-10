#include <stdio.h>
int main() {
    int n, res=0,d;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        res += d-1;
        if(res%2) puts("1");
        else puts("2");
    }
    return 0;
}
