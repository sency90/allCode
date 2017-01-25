#include <cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll b, ll s) { return (s==0)?b:gcd(s,b%s); }
ll f(ll x) { return x>>1; }
int main() {
    long long n, m;
    scanf("%lld%lld",&n,&m);
    ll g = gcd(n-1,m-1);
    ll N=(n-1)/g, M=(m-1)/g;
    ll add = (g-1)*N*M;
    printf("%lld\n", f(N+2)*f(M+2)+f(N+1)*f(M+1) + add);
    return 0;
}
