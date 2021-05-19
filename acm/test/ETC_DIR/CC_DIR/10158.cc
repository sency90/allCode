#include <cstdio>
using namespace std;
using ll=long long;
int main() {
    ll w,h; scanf("%lld%lld",&w,&h);
    ll x,y; scanf("%lld%lld",&x,&y);
    ll t; scanf("%lld", &t);
    ll tx=t+x, ty=t+y, nx,ny;
    tx%=2*w; ty%=2*h;
    if(tx>=w) nx=2*w-tx;
    else nx=tx;
    if(ty>=h) ny=2*h-ty;
    else ny=ty;
    printf("%lld %lld",nx,ny);
    return 0;
}
