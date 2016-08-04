#include <stdio.h>
#include <cstring>
using namespace std;
long long v[100010], c[100010], idx[100010];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    long long sum=0LL, ans=0LL;
    for(int i=1; i<=n; i++) {
        scanf("%lld", &v[i]);
        sum += v[i];
    }
    for(int i=1; i<=n; i++) {
        ans += (sum-v[i])*v[i];
    }
    ans/=2LL;

    long long vsum=0LL, ans2=0LL;
    int cnt=0;
    for(int i=1; i<=k; i++) {
        scanf("%lld", &c[i]);
        for(int j=c[i-1]+1; j<c[i]; j++) {
            vsum += v[j];
            idx[cnt++] = j;
        }
    }
    for(int j=c[k]+1; j<=n; j++) {
        vsum += v[j];
        idx[cnt++] = j;
    }
    for(int i=0; i<cnt; i++) {
        ans2 += (vsum-v[idx[i]])*v[idx[i]];
    }
    ans2/=2LL;

    long long ans3=0LL;
    for(int i=1; i<cnt; i++) {
        if(idx[i-1]+1 == idx[i]) ans3 += v[idx[i-1]]*v[idx[i]];
    }
    if(idx[cnt-1]==n && idx[0]==1) ans3 += v[idx[0]]*v[idx[cnt-1]];

    printf("%lld\n", ans-ans2+ans3);
    return 0;
}
