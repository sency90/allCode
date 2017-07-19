#include <iostream>
#include <algorithm>
using namespace std;
int s[1001];
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n,l; scanf("%d%d", &n,&l);
        int mx=0,x;
        for(int i=1; i<=n; i++) {
            scanf("%d", &x);
            s[i]=s[i-1]+x;
            mx = max(x,mx);
        }

        double mn=mx;
        for(int i=l; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                mn = min(mn, (double)(s[j]-s[j-i])/i);
            }
        }
        printf("%.8lf\n", mn);
    }
    return 0;
}
