#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int t, p, n, x;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d",&p,&n);
        int mn=0, mx=0;
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            mn = max(mn, min(x,p-x));
            mx = max(mx, max(x,p-x));
        }
        printf("%d %d\n",mn,mx);
    }
    return 0;
}
