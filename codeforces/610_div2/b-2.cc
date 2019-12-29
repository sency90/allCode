#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int n,p,k;
int a[200001];
pii dp[200001];
int chk[200001];
pii f(int x, int z) {
    if(x<0) return pii(0,0);
    else if(x==0) return pii(0,p);
    if(chk[x] == z) return dp[x];
    chk[x] = z;

    pii &ret = dp[x];
    ret = pii(0,0);

    if(ret.first < f(x-1,z).first) {
        ret.first = f(x-1,z).first;
    }
    if(f(x-1,z).second >= a[x]) {
        if(ret.first < f(x-1,z).first+1) {
            ret.first = f(x-1,z).first+1;
            ret.second = f(x-1,z).second - a[x];
        }
        //else ret = f(x-1,z);
    }
    if(f(x-k,z).second >= a[x]) {
        if(ret.first < f(x-k,z).first+k) {
            ret.first = f(x-k,z).first+k;
            ret.second = f(x-k,z).second - a[x];
        }
        else if(ret.first == f(x-k,z).first+k) {
            if(ret.second < f(x-k,z).second - a[x]) ret.second = f(x-k,z).second - a[x];
        }
    }
    if(ret.first == f(x-1,z).first) {
        if(ret.second < f(x-1,z).second) ret = f(x-1,z);
    } else if(ret.first < f(x-1,z).first) ret = f(x-1,z);

    return ret;
}
int main() {
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        scanf("%d%d%d",&n,&p,&k);
        for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        printf("%d\n", f(n,z).first);
    }

    //for(int i=0; i<=n; i++) {
    //    printf("%d %d\n", dp[i].first, dp[i].second);
    //}
    return 0;
}
