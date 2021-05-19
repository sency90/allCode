#include <stdio.h>
#include <cstring>
using namespace std;
long long n, l, r, d[21][21][21];
long long f(long long x, long long p, long long q) {
    if(d[x][p][q]>0) return d[x][p][q];
    if(p==1 && q==1) {
        if(x==1) return 1;
        else return 0;
    }
    if(p<1 || q<1 || p+q>x+1) return 0;
    return d[x][p][q] = ((x-2)*f(x-1,p,q) + f(x-1,p-1,q) + f(x-1,p,q-1));
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(d, 0, sizeof(d));
        scanf("%lld %lld %lld",&n,&l,&r);
        printf("%lld\n", f(n, l, r));
    }
    return 0;
}
