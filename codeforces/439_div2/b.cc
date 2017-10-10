#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll a, b;
    cin >> a >> b;
    if(a==b) puts("1");
    else {
        ll res=1;
        for(ll i=a+1; i<=b; i++) {
            res *= (i%10LL);
            res %= 10LL;
            if(res==0LL) break;
        }
        printf("%lld\n", res%10LL);
    }
    return 0;
}
