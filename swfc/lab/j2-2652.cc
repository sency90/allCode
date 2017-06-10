#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int v[19][19],d[19][1<<19];
const int inf = 0x3f3f3f3f;
int main() {
    //freopen("input.txt","r",stdin);
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&v[i][j]);
        }
    }

    memset(d,0x3f,sizeof(d));
    int lim = 1<<n;
    for(int i=0; i<n; i++) {
        if(v[0][i]) d[i][1|(1<<i)]=v[0][i];
    }
    for(int bit=3; bit<lim; bit+=2) {
        for(int i=1; i<n; i++) {
            if((bit>>i)&1) {
                int pbit = bit^(1<<i);
                for(int last=1; last<n; last++) {
                    if((bit>>last)&1 && v[last][i]) {
                        d[i][bit] = min(d[i][bit],d[last][pbit]+v[last][i]);
                    }
                }
            }
        }
    }
    int ans=inf;
    for(int i=1; i<n; i++) {
        if(v[i][0]) ans=min(ans,d[i][lim-1]+v[i][0]);
    }
    if(ans==inf) puts("0");
    else printf("%d",ans);
    return 0;
}
