#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int t,x,y,p,m,f,c;
    scanf("%d", &t);
    while(t--) {
        x=0; y=0;
        scanf("%d%d%d%d",&p,&m,&f,&c);
        int addchicken=m/p;
        y=addchicken+(c*addchicken)/f;
        x+=addchicken;
        int coupon=addchicken*c, prevCoupon=0;
        while(coupon != prevCoupon) {
            prevCoupon = coupon;
            addchicken = coupon/f;
            x+=addchicken;
            coupon = addchicken*c + coupon%f;
        }
        printf("%d\n", x-y);
    }
    return 0;
}
