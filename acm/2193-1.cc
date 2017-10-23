#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll d[91][2];
ll f(int x, int y) {
    if(x==1) return y;
    ll &ret = d[x][y];
    if(ret>=0) return ret;
    else ret=0;

    if(y) d[x][y] = f(x-1,0);
    else d[x][y] = f(x-1,1)+f(x-1,0);
    return d[x][y];
}
int main() {
    memset(d,-1,sizeof(d));
    int n; scanf("%d", &n);
    printf("%lld",f(n,0)+f(n,1));
    return 0;
}
