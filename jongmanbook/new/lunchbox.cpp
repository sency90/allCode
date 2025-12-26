#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
struct Info{
    int m,e,idx;
    Info(){}
    Info(int m, int e):m(m),e(e) {}
    bool operator<(const Info & rhs) const {
        if(e==rhs.e) return m<rhs.m;
        else return e>rhs.e;
    }
};
ll ans;
Info v[10001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;

    while(tc--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> v[i].m;
        }
        for(int i=0; i<n; i++) {
            cin >> v[i].e;
        }

        sort(v,v+n);

        ll ans=0, sum=0;
        for(int i=0; i<n; i++) {
            sum += v[i].m;
            ans = max(ans, sum + v[i].e);
        }

        printf("%lld\n", ans);
    }
    return 0;
}