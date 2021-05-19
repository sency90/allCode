#include <stdio.h>
#include <cmath>
using namespace std;
int main() {
    int n, x, i, ans=0;
    scanf("%d", &n);
    while(n>0) {
        i=sqrt(n-1);
        x=i*(i+1)/2;
        for(;;i++) {
            if(n-x<i) break;
            else x = i*(i+1)/2;
        }
        ans += i-1;
        n-=x;
    }
    printf("%d", ans);
    return 0;
}
