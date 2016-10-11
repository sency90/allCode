#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[1001][1001][2], v[1001];
int f(int l, int r, int t) {
    if(r<l) return 0;
    int &ret = d[l][r][t];
    if(ret) return ret;

    if(t) ret = max(f(l+1,r,t^1)+v[l], f(l,r-1,t^1)+v[r]);
    else ret = min(f(l+1,r,t^1),f(l,r-1,t^1));
    return ret;
}
int main() {
    int tc,n;
    scanf("%d",&tc);
    while(tc--) {
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        scanf("%d",&n);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        printf("%d\n", f(0,n-1,1));
    }
    return 0;
}
