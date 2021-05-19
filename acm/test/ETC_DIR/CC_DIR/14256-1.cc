#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> v;
void print(vector<pll>& v) {
    puts("\n!!");
    for(pll &p: v) {
        printf("%lld %lld\n", p.first, p.second);
    }
    puts("");
}
int main() {
    ll n,m; scanf("%lld%lld",&n,&m);
    ll lim = sqrt(n*m);
    for(ll i=1LL; i<=lim; i++) {
        ll t = i*i;
        for(ll j=1LL; j<=i; j++) {
        //for(ll j=1LL; j*j<=t; j++) {
            if(t%j==0) {
                v.push_back({j,t/j});
                if(t!=t/j) v.push_back({t/j,j});
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    auto it = upper_bound(v.begin(), v.end(), pll(min(n,m)+1,0LL));
    if(it!=v.end()) v.erase(it, v.end());
    v.erase(v.end(), v.end());
    for(auto &p: v) { swap(p.first, p.second); }
    sort(v.begin(), v.end());
    it = upper_bound(v.begin(), v.end(), pll(max(n,m)+1,0LL));
    if(it!=v.end()) v.erase(it, v.end());

    printf("%lu", v.size());
    return 0;
}
