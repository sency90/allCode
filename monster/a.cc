#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef pair<unsigned long long, unsigned long long> pll;
pll ps(ull x){
    if(x==1ULL) return pll(1ULL,1ULL);
    pll ret=ps(x>>1);
    if(x&1ULL) return pll((ret.first<<1)+ret.second+1ULL, ret.second+1ULL);
    else return pll((ret.first<<1)+ret.second, ret.second);
}
int main() {
    int n;
    ull s,e;
    freopen("/Users/lian/allCode/monster/input.txt", "r", stdin);
    freopen("/Users/lian/allCode/monster/output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%llu%llu",&s,&e);
        printf("%llu\n",ps(e).first-ps(s).first);
    }
    return 0;
}
