#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
auto bCmp = [](const pll& l, const pll& r) {
    return l.second>r.second;
};
auto sCmp = [](const pll& l, const pll& r) {
    if(l.first==r.first) return l.second>r.second;
    else return l.first<r.first;
};
priority_queue<pll,vector<pll>,decltype(bCmp)> big(bCmp);
priority_queue<pll,vector<pll>,decltype(sCmp)> small(sCmp);

int main() {
    int n;
    ll bs,t,w;
    scanf("%d%lld%lld",&n,&bs,&w);
    for(int i=1; i<n; i++) {
        scanf("%lld%lld",&t,&w);
        if(t>bs) big.push({t,w-t});
        else small.push({t,w-t});
    }
    int sz = big.size();
    while(!big.empty()) {
        pll x = big.top(); big.pop();
        if(x.second<bs) bs-=x.second+1;
        else break;
        while(!small.empty()) {
            x=small.top();
            if(x.first>bs) big.push(x);
            else break;
            small.pop();
        }
        sz = min(sz, (int)big.size());
    }
    printf("%d\n", sz+1);
    return 0;
}
