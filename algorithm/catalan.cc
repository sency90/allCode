#include <cstdio>
using namespace std;
long long d[67][67];
long long combi(int n, int r) {
    if(r==0||n==r) return 1LL;
    if(d[n][r]) return d[n][r];
    return d[n][r]=combi(n-1,r-1)+combi(n-1,r);
}
long long catalan(int x) { return combi(x<<1,x)/(x+1LL); }
int main() {
    int n; scanf("%d",&n);
    printf("%lld\n",catalan(n));
    return 0;
}
