#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
set<int> s;
vector<int> v;
ll cnt[400001];
int main() {
    int n; scanf("%d",&n);
    v.resize(n);
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        cnt[x]++;
        s.insert(x);
    }
    auto it = s.end();
    int e = *(--it);
    int lim = e<<1;
    ll mx=0LL;
    for(int i=1; i<=lim; i++) cnt[i]+=cnt[i-1];
    for(auto p: s) {
        ll sum=0LL;
        for(ll j=p; j<=e; j+=p) {
            sum+=j*(cnt[j+p-1]-cnt[j-1]);
        }
        mx=max(mx,sum);
    }
    printf("%lld", mx);
    return 0;
}
