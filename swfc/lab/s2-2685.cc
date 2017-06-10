#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int c,v,l;
ll d[501][2];
const ll mod=1e9+7LL;
int main() {
    int tc;
    scanf("%d",&tc);
    for(int z=1; z<=tc; z++) {
        memset(d,0,sizeof(d));
        scanf("%d%d%d",&c,&v,&l);
        if(l==1) printf("Case #%d: %d\n",z,v);
        else {
            d[1][0]=c;
            d[1][1]=v;
            for(int i=2; i<=l; i++) {
                d[i][0] = d[i-1][1]*c%mod;
                d[i][1] = (d[i-1][1]+d[i-1][0])*v%mod;
            }
            printf("Case #%d: %lld\n",z,d[l][1]);
        }
    }
    return 0;
}
