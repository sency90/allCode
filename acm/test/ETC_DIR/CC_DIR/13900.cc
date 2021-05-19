#include <cstdio>
using namespace std;
typedef long long ll;
ll cnt[10001], mul[10001];
int main() {
    int n,x;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for(int i=1; i<=10000; i++) {
        if(!cnt[i]) continue;
        mul[i]+=(i*(cnt[i]-1LL)*cnt[i])>>1;
        for(int j=i+1; j<=10000; j++) {
            if(cnt[j]) mul[i]+=j*cnt[j]*cnt[i];
        }
    }

    ll ans=0LL;
    for(int i=1; i<=10000; i++) {
        if(cnt[i]) ans+=(ll)i*mul[i];
    }
    printf("%lld\n", ans);
    return 0;
}
