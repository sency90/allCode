#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[400001];
int n;
inline int ABS(int x) {
    return (x<0)?-x:x;
}
int diff(int x) {
    int ret=0;
    int prev;
    if(a[0]==-1) prev=x;
    else prev = a[0];
    for(int i=1; i<n; i++) {
        if(a[i]==-1) {
            ret = max(ret, ABS(x-prev));
            prev = x;
        }
        else {
            ret = max(ret, ABS(a[i]-prev));
            prev = a[i];
        }
    }
    return ret;
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        int mx = -1, mn=0x3f3f3f3f;
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            mx = max(a[i], mx);
            if(a[i]!=-1) mn = min(a[i], mn);
        }
        if(mx==-1) {
            puts("0 0");
            continue;
        }
        ll lo=mn, hi=mx;
        while(hi-lo >= 3) {
            ll p = (lo*2 + hi)/3;
            ll q = (lo + hi*2)/3;
            if(diff(p) <= diff(q)) hi=q;
            else lo = p;
        }

        int ans=0;
        int mndiff = 0x3f3f3f3f;
        for(int i=lo; i<=hi; i++) {
            int d = diff(i);
            if(d < mndiff) {
                mndiff = d;
                ans = i;
            }
        }

        printf("%d %d\n", mndiff, ans);
    }
    return 0;
}


