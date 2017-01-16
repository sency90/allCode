#include <cstdio>
using namespace std;
typedef long long ll;
//const ll mod = 1e9+7;
ll p[2001][2001];
ll f(int n, int g) {
    ll &ret = p[n][g];
    if(ret) return ret;
    if(g==0) return ret=1ll;
    if(n==1) return ret=g+1ll;
    for(int i=0; i<=g; i++) {
        ret += f(n-1,i);
        //ret %= mod;
    }
    return ret;
}
int main() {
    for(int i=1; i<=5; i++) {
        for(int j=0; j<=10; j++) {
            printf("%lld ", f(i,j));
        }
        puts("");
    }
    return 0;
}
