#include <cstdio>
#include <climits>
using namespace std;
typedef long long ll;
ll d[200];
ll f(int x) {
    if(x==1) return d[x]=2LL;
    else if(x==2) return d[x]=3LL;
    if(d[x]) return d[x];
    return d[x]=f(x-1)+f(x-2);
}
int main() {
    ll n; scanf("%lld", &n);
    f(90);
    for(int i=1; i<=90; i++) {
        if(d[i]>n) return 0&printf("%d\n", i-1);
    }
    return 0;
}
