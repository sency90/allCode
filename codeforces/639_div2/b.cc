#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
ull d[1000001];
ull f(int x) {
    if(x==0) return 0;
    else if(d[x]>0ULL) return d[x];
    else return d[x] = f(x-1)+3ULL*x-1ULL;
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n; scanf("%d", &n);
        ull r=n;
        int ans=0, lo=1, hi=1000000;
        while(r>=2ULL) {
            while(lo<=hi) {
                int mid = (lo+hi)/2;
                if(f(mid)<=r) lo=mid+1;
                else hi=mid-1;
            }
            r-=f(lo-1);
            ans++;
            hi=lo-1; lo=1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
