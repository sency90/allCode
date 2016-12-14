#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll d[101][101][101], mod=1e9+7LL;
ll f(int x, int l, int r) {
    if(l==1 && r==1) {
        if(x==1) return 1LL;
        else return 0LL;
    } else if(l<1 || r<1 || l+r>x+1) return 0LL;

    ll &ret = d[x][l][r];
    if(ret) return ret;
    return ret = ((x-2)*f(x-1,l,r) + f(x-1,l-1,r) + f(x-1,l,r-1))%mod;
}
int main() {
    int n,l,r;
    memset(d,0,sizeof(d));
    scanf("%d%d%d",&n,&l,&r);
    printf("%lld\n",f(n,l,r));
    return 0;
}
