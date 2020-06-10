#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int allbit, inf=0x3f3f3f3f;
ll llinf = 0x3f3f3f3f3f3f3f3fLL;

char v[15][51];
int n,k,cnt,len[15];
int prevlen[1<<15], idx[1<<15], M[50*15];
ll dp[1<<15][101];
inline ll gcd(ll b, ll s) { return (s==0LL)?b:gcd(s,b%s); }
int dpR[15][50*15+1];
inline int getPrevLen(int bit) {
    if(bit==0) return 0;
    else if(prevlen[bit]!=inf) return prevlen[bit];
    prevlen[bit] = getPrevLen(bit-(bit&-bit)) + len[idx[bit&-bit]];
    return prevlen[bit];
}
inline int getR(int idx, int R, int prevlen) {
    int &ret = dpR[idx][prevlen];
    if(ret!=inf) return (ret+R)%k;
    else ret=0;

    for(int i=0; i<len[idx]; i++) {
        ret+=M[i+prevlen]*(v[idx][i]-'0');
    }
    ret%=k;
    return (ret+R)%k;
}
ll f(int bit, int r) {
    ll &ret = dp[bit][r];
    if(ret != llinf) return ret;
    else ret=0LL;
    if(bit == allbit) return ret=(r==0);

    int prevlen = getPrevLen(bit);
    for(int i=0,t=1; i<n; i++, t<<=1) {
        if(bit & t) continue;
        ret += f(bit|t, getR(i,r,prevlen));
    }
    return ret;
}
int main() {
    memset(prevlen, 0x3f, sizeof(prevlen));
    memset(dp, 0x3f, sizeof(dp));
    memset(dpR, 0x3f, sizeof(dpR));
    for(int i=0; i<15; i++) idx[1<<i] = i;
    scanf("%d",&n);

    allbit = (1<<n)-1;
    for(int i=0; i<n; i++) {
        scanf("%s", v[i]);
        len[i] = strlen(v[i]);
        reverse(v[i], v[i]+len[i]);
    }
    scanf("%d",&k);

    M[0] = 1;
    for(int i=1; i<50*15; i++) M[i] = M[i-1]*10%k;

    ll ja=f(0,0), mo=1LL;
    for(ll i=1LL; i<=n; i++) {
        ll G=gcd(ja,i);
        ja/=G;
        mo*=i/G;
    }
    printf("%lld/%lld\n", ja, mo);
    return 0;
}
