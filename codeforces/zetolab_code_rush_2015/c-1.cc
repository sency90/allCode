#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll c,hr,hb,wr,wb;
    cin >>c>>hr>>hb>>wr>>wb;
    if(double(hr)/wr<double(hb)/wb) {
        swap(hr,hb);
        swap(wr,wb);
    }
    ll lim = sqrt(c), mx=0;
    if(wr>1000) {
        for(ll qr=0; qr*wr<=c; qr++) {
            ll qb=(c-(qr*wr))/wb;
            mx = max(mx, qr*hr+qb*hb);
        }
        printf("%lld\n", mx);
    } else {
        ll lim=c/1000;
        for(ll qr=0; qr<=lim; qr++) {
            if(c<qr*wr) break;
            ll qb=(c-(qr*wr))/wb;
            mx = max(mx, qr*hr+qb*hb);
        }
        printf("%lld\n", mx);
    }
    return 0;
}
