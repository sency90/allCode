#include <cstdio>
using namespace std;
int mod = 1e9+7;
const int lim = 1000000000;
int spow(int n, int r) {
    if(r==0) return 1;
    int ret = spow(n,r>>1);
    ret = (long long)ret*ret%mod;
    if(r&1) return ((long long)ret*r)%mod;
    else return ret;
}
int main() {
    int pv=1,v,x;
    freopen("./output2.txt", "w", stdout);
    for(int i=1; i<=lim; i++) {
        v=(long long)pv*i%mod;
        x=spow(v,mod-2);
        printf("%d\n", x);
        pv=v;
    }
    return 0;
}
