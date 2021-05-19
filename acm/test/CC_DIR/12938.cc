#include <stdio.h>
#include <algorithm>
#include <map>
#define MOD 1000000009LL
using namespace std;

long long d[1001][1001];
map<int, long long> cnt;
long long f(long long n, long long k) {
    if(n==k || k==0LL) return 1LL;
    if(d[n][k] > 0) return d[n][k];
    return d[n][k] = (f(n-1,k-1)+f(n-1,k))%MOD;
}
int main() {
    long long ans = 1LL;
    int n, d, tmp;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        tmp = d;
        for(int j=2; j*j<=tmp; j++) {
            while(d%j == 0) {
                cnt[j]++;
                d /= j;
            }
        }
        if(d!=1) cnt[d]++;
    }

    for(pair<const int, long long> &p : cnt) {
        ans = ans * f(p.second+n-1, p.second) % MOD;
    }
    printf("%lld", ans);
    return 0;
}
