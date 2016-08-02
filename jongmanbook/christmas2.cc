#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const long long MOD = 20091101LL;
//map<int, vector<int> > cnt;
int psum[100001], cnt[100001];
long long combi(long long n) { return n*(n-1LL)/2LL; }
int t,n,k,in;
int f() {
    vector<int> ret(n+1, 0), prev(k, -1);
    ret[0]=0;
    prev[psum[0]]=0;
    for(int i=1; i<=n; i++) {
        ret[i] = ret[i-1];
        int loc = prev[psum[i]];
        if(loc!=-1) ret[i] = max(ret[i], ret[loc]+1);
        prev[psum[i]] = i;
    }
    return ret.back();
}
int main() {
    scanf("%d", &t);
    while(t--) {
        long long ans = 0LL;
        memset(cnt, 0, sizeof(cnt));
        memset(psum, 0, sizeof(psum));
        cnt[psum[0]]++;
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++) {
            scanf("%d",&in);
            psum[i] = (psum[i-1]+in)%k;
            cnt[psum[i]]++;
            //cnt[psum[i]].push_back(i);
        }
        for(int i=0; i<k; i++) {
            if(cnt[i]>=2) ans = (ans + combi(cnt[i])) % MOD;
        }
        printf("%lld %d\n", ans, f());
    }
    return 0;
}
