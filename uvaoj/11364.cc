#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int tc; scanf("%d",&tc);
    while(tc--) {
        int n; scanf("%d", &n);
        int mx=0,mn=0x3f3f3f3f;
        for(int i=0; i<n; i++) {
            int x;
            scanf("%d",&x);
            mx=max(x,mx);
            mn=min(x,mn);
        }
        printf("%d\n",(mx-mn)<<1);
    }
    return 0;
}
