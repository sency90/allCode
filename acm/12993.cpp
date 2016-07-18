#include <stdio.h>
int main() {
    long long x, y, res[37], i;
    scanf("%lld%lld",&x,&y);
    if(x==0LL && y==0LL) {
        puts("1");
        return 0;
    }
    long long a = 2*(x+y)+1;
    if(a%3!=0) {
        puts("0");
        return 0;
    }

    res[0] = 1LL;
    for(i=0; i<35; i++) {
        if(res[i]==a) break;
        else if(res[i]>a) {
            puts("0");
            return 0;
        }
        res[i+1]=3*res[i];
    }
    for(int j=i-1; j>=0; j--) {
        if(x>y) {
            x-=res[j];
            if(x<0) {
                puts("0");
                return 0;
            }
        } else {
            y-=res[j];
            if(y<0) {
                puts("0");
                return 0;
            }
        }
    }
    if(x==0 && y==0) puts("1");
    else puts("0");
    return 0;
}
