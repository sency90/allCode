#include <bits/stdc++.h>
using ll = long long;
using namespace std;
inline ll ABS(ll x) {
    return (x<0LL)?-x:x;
}
ll N;
ll f(ll A, ll a, ll n) {
    ll rmn = N-n;
    if(rmn == 0) return A;
    else if(rmn == 1) return a;
    else if(rmn == 2) return ABS(A-a);
    else {
        if(a==0) {
            return f(A, a, n+(rmn/3LL)*3LL);
        }
        ll mxs = A/(2*a);
        if(mxs==0LL) {
            return f(a,ABS(A-a),n+1);
        }
        else {
            ll lo=1, hi=mxs;
            while(lo<=hi) {
                ll mid = (lo+hi)/2;
                if(n+3*mid<=N) lo=mid+1;
                else hi=mid-1;
            }
            ll s = lo-1;
            return f(A-2*a*s, a, n+3*s);
        }
    }
    
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll s0, s1;
    int n;
    cin >> s0 >> s1 >> n;
    for(int i=0; i<n; i++) {
        cin >> N;
        printf("%lld\n", f(s0,s1,0));
    }
    return 0;
}