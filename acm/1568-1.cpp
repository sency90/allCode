#include <stdio.h>
int main() {
    int n, cnt=0;
    scanf("%d", &n);
    for(int i=1; n>0; i++) {
        if(n-i<0) i=1;
        cnt++;
        n-=i;
    }
    printf("%d", cnt);
    return 0;
}
