#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 20091101LL;
ll ps[100001], d[100001], in;
int cnt[100001], last[100001], lastPos[100001];
ll combi(int n) { return n*(n-1LL)/2LL; }
ll f(int n) {
    if(n==0) return 0LL;
    else if(n==1) {
        if(ps[n]==0) return 1LL;
    }
    ll &ret = d[n];
    if(ret!=-1LL) return ret;
    else ret = 0LL;

    ret = f(n-1);
    if(lastPos[n]!=0) {
        if(ps[n]==0) ret = max(f(lastPos[n])+1,ret);
        else ret = max(f(lastPos[n]-1)+1,ret);
    }
    return ret;
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n, k;
        scanf("%d%d",&n,&k);
        memset(d, -1, sizeof(d));
        memset(last, 0, sizeof(last));
        memset(lastPos, 0, sizeof(lastPos));
        memset(cnt, 0, sizeof(cnt));
        cnt[0]=1;
        for(int i=1; i<=n; i++) {
            scanf("%lld", &in);
            ps[i]=(ps[i-1]+in)%k;
            lastPos[i]=last[ps[i]];
            last[ps[i]]=i;
            cnt[ps[i]]++;
        }

        ll ans=0LL;
        for(int i=0; i<k; i++) {
            if(cnt[i]>=2) {
                ans+=combi(cnt[i]);
                ans%=MOD;
            }
        }
        printf("%lld %lld\n", ans, f(n));
    }
    return 0;
}
