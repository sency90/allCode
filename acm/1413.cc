#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long d[21][21];
long long gcd(long long x, long long y) {
    return x%y==0LL? y:gcd(y,x%y);
}
long long f(int n, int m) {
    if(m<0) return 0LL;
    if(n==0) {
        if(m==0) return 1LL;
        else return 0LL;
    }

    long long &ret = d[n][m];
    if(ret!=-1) return ret;
    return ret = f(n-1,m-1) + (n-1)*f(n-1,m);
}
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    memset(d, -1, sizeof(d));
    int lim = min(n,m);
    long long c = 0LL;
    for(int i=0; i<=lim; i++) {
        c += f(n,i);
    }
    long long p = 1LL;
    for(long long i=1LL; i<=n; i++) p *= i;
    long long x=gcd(c, p);
    printf("%lld/%lld", c/x, p/x);
    return 0;
}
