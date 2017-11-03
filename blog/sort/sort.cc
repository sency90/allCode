#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;
typedef long long ll;
int cnt[100001], idx[2][100001];
template <typename T> inline T MAX(T x, T y) { return x>y?x:y; }

ll tmp[100001];
void sort(vector<ll>& v) {
    ll mx=0LL;
    int n=v.size(), mask=(1<<13)-1, t=0;
    for(int i=0; i<n; i++) idx[0][i]=i, mx=MAX<ll>(mx,v[i]);
    for(int z=0; (mx>>(13*z)); z++, t^=1) {
        int shift = 13*z;
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<n; i++) cnt[(v[idx[t][i]]>>shift) & mask]++;
        for(int i=1; i<=mask; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[t^1][--cnt[(v[idx[t][i]]>>shift) & mask]]=idx[t][i];
    }
    for(int i=0; i<n; i++) tmp[i]=v[idx[t][i]];
    for(int i=0; i<n; i++) v[i]=tmp[i];
}

vector<ll> v;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n; scanf("%d",&n);
    assert(n==100000);

    const ll lim=1e18;
    v.clear(); v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%lld",&v[i]);
        assert(0<v[i] && v[i]<lim);
    }
    sort(v);
    for(int i=0; i<n; i++) printf("%lld\n",v[i]);
    return 0;
}
