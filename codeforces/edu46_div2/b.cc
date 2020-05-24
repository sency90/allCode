#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll v[100010], r1sum[100010], r2sum[100010], diff[100010];
int main() {
    int n, M; scanf("%d%d", &n,&M);
    v[0]=0, v[n+1]=M;
    for(int i=1; i<=n+1; i++) {
        if(i!=n+1) scanf("%lld", &v[i]);
        diff[i-1] = v[i]-v[i-1];
    }
    for(int i=n+1; i>=0; i--) {
        r1sum[i] = diff[i+1] + r1sum[i+2];
        r2sum[i] = diff[i+2] + r2sum[i+2];
    }
    long long sum=0, ans=0;
    for(int i=0; i<=n+1; i++) {
        if(diff[i]==1) {
            if(i%2 == 0) ans = max(ans, max(sum+diff[i]+r2sum[i], sum+r1sum[i]));
            else continue;
        } else if(i%2 == 0) ans = max(ans, max(sum+diff[i]-1+r1sum[i], sum+diff[i]+r2sum[i]));
        else ans = max(ans, sum+diff[i]-1+r2sum[i]);
        if(i%2 == 0) sum+=diff[i];
    }
    printf("%lld\n", ans);
    return 0;
}
