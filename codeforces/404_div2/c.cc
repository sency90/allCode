#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    ll n,m;
    scanf("%lld%lld",&n,&m);
    if(n<=m) printf("%lld\n",n);
    else {
        ll lo=0, hi=1e10, bs=n-m;
        while(lo<hi) {
            ll mid = (lo+hi)/2LL;
            if(mid*(mid+1LL)/2LL<bs) lo=mid+1LL;
            else hi=mid;
        }
        printf("%lld\n",m+lo);
    }
    return 0;
}
