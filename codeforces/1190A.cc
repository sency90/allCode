#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> p;
int main() {
    ll n,m,k; scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=0; i<m; i++) {
        ll x; scanf("%lld", &x);
        p.push_back(x);
    }


    int ans=0;
    for(int i=0; i<m; i++) {
        ll idx = p[i]-1; //v에서 p[i]가 있는 곳의 위치
        ll group = (idx-i)/k;
        ll mxidx = min(group*k+k-1+i, n-1);

        auto jt = lower_bound(p.begin()+i, p.end(), mxidx+1);
        if(jt==p.end() || *jt != mxidx+1) jt--;

        i = jt - p.begin();
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
