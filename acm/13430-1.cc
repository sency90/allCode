#include <cstdio>
#include <vector>
using namespace std;
typedef unsigned long long ull;
vector<ull> v,d;
const ull mod = 1e9+7ULL;
bool chk[52];
ull gcd(ull b, ull s) { return (s==0)?b:gcd(s,b%s); }
int main() {
    ull n,k;
    scanf("%lld%lld",&n,&k);
    ull res = 1ull;

    for(ull x=k; x<=n+k; x++) {
        v.push_back(x);
    }
    for(ull x=n+1; x>=1; x--) {
        d.push_back(x);
    }

    while(true) {
        bool good = true;
        for(int i=0; i<v.size(); i++) {
            for(int j=0; j<d.size(); j++) {
                if(!chk[j]) {
                    good = false;
                    ull x=gcd(v[i],d[j]);
                    v[i]/=x; d[j]/=x;
                    if(d[j]==1) chk[j]=true;
                }
            }
        }
        if(good) break;
    }
    for(ull x: v) {
        res *= x;
        res %= mod;
    }
    printf("%llu\n", res);
    return 0;
}
