#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,k;
inline int judge(int x) {
    int ret = 0;
    int mn = min(n,x);
    for(int i=1; i<=mn; i++) {
        int p = x/i;
        if(p==0) break;
        ret += min(n,p);
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&k);
    int lo=1, hi=min((ll)n*n,(ll)1e9);
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(judge(mid)>=k) hi = mid-1;
        else lo = mid+1;
    }
    printf("%d", hi+1);
    return 0;
}
