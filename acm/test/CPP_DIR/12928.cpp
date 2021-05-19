#include <stdio.h>
int main() {
    int n, s;
    scanf("%d%d",&n,&s);
    int ans = (n-1)*(n-2)/2;
    printf("ans: %d, %d\n", ans, n-2);
    if(s<=ans && n-2<=s && s>=1 && s<=1000) puts("1");
    else puts("0");
    return 0;
}
