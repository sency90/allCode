#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const ll MOD = 998244353LL;
ll d[5001][5001];
ll f(int x, int y) {
    if(x>y) swap(x,y);
    if(x==0) return 1LL;
    ll &ret = d[x][y];
    if(ret>=0) return ret;
    else ret=0;

    ret = (f(x-1,y-1)*y + f(x-1,y)) % MOD;
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int a,b,c;
    memset(d,-1,sizeof(d));
    cin >> a >> b >> c;
    ll res = 1;
    res *= f(a,b); res %= MOD;
    res *= f(b,c); res %= MOD;
    res *= f(a,c); res %= MOD;
    printf("%lld", res);
    return 0;
}
