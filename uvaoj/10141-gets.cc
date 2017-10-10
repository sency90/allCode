#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char ign[101], s[101], ans[101];
int main() {
    for(int z=1;;z++) {
        int n,p; scanf("%d%d",&n,&p); gets(ign);
        if(n==0) return 0;
        while(n--) gets(ign);

        int mxr=0; double mnd=int(0x3f3f3f3f);
        for(int i=0; i<p; i++) {
            double d; int r;
            gets(s);
            scanf("%lf%d", &d,&r); gets(ign);
            if(mxr<r || (mxr==r && mnd>d)) {
                mxr=r; mnd=d;
                memcpy(ans,s,sizeof(s));
            }
            for(int j=0; j<r; j++) gets(ign);
        }
        if(z!=1) puts("");
        printf("RFP #%d\n%s",z,ans);
    }
    return 0;
}

