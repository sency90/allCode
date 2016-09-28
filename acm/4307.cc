#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int tc,l,n,s,b,x;
    scanf("%d", &tc);
    while(tc--) {
        int mx1=0, mx2=0;
        scanf("%d%d",&l,&n);
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            s=x, b=l-x;
            if(s>b) swap(s,b);
            mx1 = max(mx1, s);
            mx2 = max(mx2, b);
        }
        printf("%d %d\n", mx1, mx2);
    }
    return 0;
}
