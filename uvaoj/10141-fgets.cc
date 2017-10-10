#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char ign[101], s[101], ans[101];
int main() {
    for(int z=1;;z++) {
        int n,p; scanf("%d%d",&n,&p); fgets(ign,101,stdin);
        if(n==0) return 0;
        while(n--) fgets(ign,101,stdin);

        int mxr=0; double mnd=int(0x3f3f3f3f);
        for(int i=0; i<p; i++) {
            double d; int r;
            fgets(s,101,stdin);
            scanf("%lf%d", &d,&r); fgets(ign,101,stdin);
            if(mxr<r || (mxr==r && mnd>d)) {
                mxr=r; mnd=d;
                memcpy(ans,s,sizeof(s));
            }
            for(int j=0; j<r; j++) fgets(ign,101,stdin);
        }
        if(z!=1) puts("");
        printf("RFP #%d\n%s",z,ans);
    }
    return 0;
}

