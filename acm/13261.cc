#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
ll v[8001], d[801][8001], p[801][8001], psum[8001];
ll f(int g, int l) {
    ll& ret = d[g][l];
    if(g==1) return ret = (psum[l]-psum[0])*l;
    if(ret) return ret;
    else ret = inf;
    for(int k=1; k<=l; k++) {
        ret = min(ret,f(g-1,k)+(psum[l]-psum[k])*(l-k));
    }
    return ret;
}
int main() {
    int L,G;
    scanf("%d%d",&L,&G);
    memset(p,0x3f,sizeof(p));
    for(int i=1; i<=L; i++) {
        scanf("%lld", &v[i]);
        psum[i]=psum[i-1]+v[i];
    }
    printf("%lld\n", f(G,L));
    return 0;
}
