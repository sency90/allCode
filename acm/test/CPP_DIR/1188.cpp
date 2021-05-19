#include <stdio.h>
int main() {
    int n, m, cnt=0;
    scanf("%d %d", &n, &m);
    int len = m*n;
    for(int i=1; n*i<len; i++) {
        if(n*i%m!=0) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
