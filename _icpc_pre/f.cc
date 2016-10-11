#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int v[501], d[501][501], s[501];
int f(int x, int y) {
    if(x==y) return 0;

    int &ret = d[x][y];
    if(ret) return ret;
    else ret=0x3f3f3f3f;

    for(int i=x; i<y; i++) {
        ret = min(ret, f(x,i)+f(i+1,y)+(s[y]-s[x-1]));
    }
    return ret;
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        memset(d, 0, sizeof(d));
        memset(s, 0, sizeof(s));
        int n; scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &v[i]);
            s[i]+=s[i-1]+v[i];
        }
        printf("%d\n", f(1,n));
    }
    return 0;
}
