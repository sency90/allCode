#include <stdio.h>
long long x, y;
bool f(long long x, long long y) {
    if(x==0 && y==0) return true;
    if((x+1)%3==0) {
        if(y%3==0) return f((x+1)/3, y/3);
        else return false;
    } else if((x-1)%3==0) {
        if(y%3==0) return f((x-1)/3, y/3);
        else return false;
    } else if((y+1)%3==0) {
        if(x%3==0) return f(x/3, (y+1)/3);
        else return false;
    } else if((y-1)%3==0) {
        if(x%3==0) return f(x/3, (y-1)/3);
        else return false;
    } else return false;
}
int main() {
    scanf("%lld%lld",&x,&y);
    if(f(x,y)) puts("1");
    else puts("0");
    return 0;
}
