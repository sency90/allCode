#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    for(int z=1; z<=tc; z++) {
        priority_queue<ll> mxh;
        ll n,k; cin >> n >> k;
        mxh.push(n);

        ll x,l,r;
        for(int i=0; i<k; i++) {
            x=mxh.top(); mxh.pop();
            l=(x-1LL)/2LL;
            r=x-l-1;
            mxh.push(l); mxh.push(r);
        }

        printf("Case #%d: %lld %lld\n", z,r,l);
    }
    return 0;
}
