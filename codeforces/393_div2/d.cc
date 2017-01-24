#include <cstdio>
using namespace std;
typedef long long ll;
int v[100001];
ll f(int x) {
    ll ret = 0;
    if(x>180) {
        ll t = x/1440;
        if(x%1440 == 0) ret = 120*t;
        else ret = 120*(t+1);
    }
    if()
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d",&x);
        ll res = f(x);
        if(amt >= res) puts("0");
        else {
            ll charge = res-amt;
            amt=res;
            printf("%lld\n", charge);
        }
    }
    return 0;
}
