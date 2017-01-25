#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll c,hr,hb,wr,wb;
ll calc(ll x) { return (c-wr*x)/wb; }
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>c>>hr>>hb>>wr>>wb;
    ll l=0, r=c/wr, mx=0;
    for(int i=0; i<1000000; i++) {
        ll xl=(l*13589+r)/13590;
        ll xr=(l+r*13589+13589)/13590;
        ll yl=calc(xl), yr=calc(xr);
        mx = max({mx, hr*xl+hb*yl, hr*xr+hb*yr});
        if(hr*xl+hb*yl > hr*xr+hb*yr) l=xl;
        else r=xr;
    }
    printf("%lld", mx);
    return 0;
}
