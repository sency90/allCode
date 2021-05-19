#include <stdio.h>
int main() {
    int a,b,c, ans;
    scanf("%d%d%d",&a,&b,&c);
    if((a+b+c)%3==0) {
        if(a%3!=b%3 && a%3!=c%3 && b%3!=c%3) ans = (a+b+c)/3+1;
        else ans = (a+b+c)/3;
    } else ans = (a+b+c)/3+1;
    printf("%d", ans);
    return 0;
}
