#include <cstdio>
#include <algorithm>
using namespace std;
int a[100001],b[100001],cc;
int mnb=0x3f3f3f3f, mxb=0ll;
int main() {
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) {
        scanf("%d", &cc);
        b[i]=cc+a[i];
        mnb=min(mnb,b[i]);
        mxb=max(mxb,b[i]);
    }
    if(mxb-mnb>r-l) puts("-1");
    else {
        int df=r-mxb;
        for(int i=0; i<n; i++) printf("%d ", b[i]+df);
    }
    return 0;
}
