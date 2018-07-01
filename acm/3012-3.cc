#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll d[201][201];
ll z[201][201];
char s[201];
const ll MOD = 100000LL;
inline int getCnt(int l, int r) {
    if(s[l]=='?' && s[r]=='?') return 3;
    else if(s[l]=='?' && (s[r]==')' || s[r]=='}' || s[r]==']')) return 1;
    else if(s[r]=='?' && (s[l]=='(' || s[l]=='{' || s[l]=='[')) return 1;
    else if(s[l]=='(' && s[r]==')') return 1;
    else if(s[l]=='{' && s[r]=='}') return 1;
    else if(s[l]=='[' && s[r]==']') return 1;
    else return 0;
}
ll f(int l, int r) {
    ll &ret = d[l][r];
    if(l>r) return 1LL;
    else if(l==r) return ret=0LL;
    if(ret!=-1) return ret;
    else ret=0;

    for(int i=l+1; i<=r; i+=2) {
        ret += getCnt(l,i)*f(l+1,i-1)*f(i+1,r);
        ret %= MOD;
    }
    return ret;
}
ll g(int l, int r) {
    ll &ret = z[l][r];
    if(l>r) return 1LL;
    else if(l==r) return ret=0LL;
    if(ret!=-1) return ret;
    else ret=0;

    for(int i=l+1; i<=r; i+=2) {
        ret += getCnt(l,i)*g(l+1,i-1)*g(i+1,r);
    }
    return ret;
}

int main() {
    memset(d,-1,sizeof(d));
    memset(z,-1,sizeof(z));
    int n; scanf("%d", &n);
    scanf("%s", s);

    if(n&1) return 0&puts("0");
    ll ans = f(0, n-1);
    ll ans2 = g(0, n-1);
    if(ans == ans2) printf("%lld", ans);
    else printf("%05lld", ans);

    return 0;
}
