#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define LEFT 0
#define RIGHT 1
typedef long long ll;
ll s[1002], d[1002][1002][2], pos[1002];
bool chk[1002][1002][2];
int n,m;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll f(int l, int r, int p) {
    if(l==r) {
        if(l==m) return 0LL;
        else return inf;
    }
    ll &ret = d[l][r][p];
    if(chk[l][r][p]) return ret;
    chk[l][r][p]=true;

    if(p==LEFT) {
        ret = min(ret, f(l+1,r,LEFT)+(s[l]+s[n]-s[r])*(pos[l+1]-pos[l]));
        ret = min(ret, f(l+1,r,RIGHT)+(s[l]+s[n]-s[r])*(pos[r]-pos[l]));
    } else { //else if(p==RIGHT)
        ret = min(ret, f(l,r-1,LEFT)+(s[l-1]+s[n]-s[r-1])*(pos[r]-pos[l]));
        ret = min(ret, f(l,r-1,RIGHT)+(s[l-1]+s[n]-s[r-1])*(pos[r]-pos[r-1]));
    }
    return ret;
}
int main() {
    memset(d,0x3f,sizeof(d));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        ll w;
        scanf("%lld%lld",&pos[i],&w);
        s[i]=s[i-1]+w;
    }

    printf("%lld", min(f(1,n,0),f(1,n,1)));
    return 0;
}
