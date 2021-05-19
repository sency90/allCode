#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n,x,y,mnx,mny,mxx,mxy;
    mnx=mny=0x3f3f3f3f; mxx=mxy=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&x,&y);
        mnx = min(mnx, x);
        mny = min(mny, y);
        mxx = max(mxx, x);
        mxy = max(mxy, y);
    }
    if(mxy-mny > mxx-mnx) printf("%d\n", (mxy-mny)*(mxy-mny));
    else printf("%d\n", (mxx-mnx)*(mxx-mnx));
    return 0;
}
