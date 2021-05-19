#include <cstdio>
using namespace std;
const long long MOD = 987654321LL;
long long d[10001];
long long f(int x) {
    if(x==0||x==2) return 1LL;
    if(d[x]>0LL) return d[x];

    int lim = x-2;
    for(int i=0; i<=lim; i+=2) {
        d[x]+=f(i)*f(lim-i);
        if(d[x]>=MOD) d[x]%=MOD;
    }
    return d[x];
}
int main() {
    int n; scanf("%d", &n);
    if(n==0) puts("0");
    else printf("%lld", f(n));
    return 0;
}
