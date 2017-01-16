#include <cstdio>
#include <vector>
using namespace std;
vector<int> vx, vy;
typedef long long ll;
int main() {
    ll a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(a>c||b>d) puts("-1");
    else {
        //if(a==c&&b==d) return 0&puts("0");
        int xi,yi;
        ll i,x,y;

        for(i=0LL; (1LL<<i)*a<=c; i++);
        xi=i-1; x=c-a*(1LL<<(i-1));

        for(i=0LL; (1LL<<i)*b<=d; i++);
        yi=i-1; y=d-b*(1LL<<(i-1));

        if(xi==yi && x==y) {
            ll s=1LL<<(i-1);
            int cnt=0;
            while(x!=0) {
                if(x-s>=0) {
                    x-=s;
                    cnt++;
                } else s>>=1;
            }
            printf("%d", xi+cnt);
        } else puts("-1");
    }
    return 0;
}
