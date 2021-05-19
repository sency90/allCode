#include <cstdio>
using namespace std;
typedef long long ll;
ll mod = 1e9+7LL;
ll d[101][101][101];
ll f(int x, int l, int r) {
    if(l==1 && r==1) return (x==1);
    else if(l<1 || r<1 || l+r>x+1) return 0;
    ll &ret = d[x][l][r];
    if(ret) return ret;
    return ret = ((x-2)*f(x-1,l,r)+f(x-1,l-1,r)+f(x-1,l,r-1))%mod;
}
int main() {
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    printf("%lld",f(n,l,r));
    return 0;
}
