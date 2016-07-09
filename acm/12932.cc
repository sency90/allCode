#include <stdio.h>
#include <map>
using namespace std;
#define MOD 1000000009LL
map<int, int> cnt;
long long d[501][501];
long long f(long long n, long long k) {
    if(n==k || k==0LL) return 1LL;
    if(d[n][k] > 0) return d[n][k];
    return d[n][k] = (f(n-1,k-1)+f(n-1,k))%MOD;
}
int main() {
    int n, d;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &d);
        cnt[d]++;
    }
    long long res=1LL, x=n;
    int prev=0;
    for(auto &p : cnt) {
        if(cnt[p.first]==0) continue;
        x -= cnt[prev];
        res = (res*f(x,cnt[p.first]))%MOD;
        prev = p.first;
    }
    printf("%lld", res);
    return 0;
}
