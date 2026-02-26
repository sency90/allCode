#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
int r[201], p[201];
int GCD(int b, int s) {
    if(s==0) return b;
    return GCD(s, b%s);
}
int AllGCD(int* v, int n) {
    int pv = v[0];
    for (int i = 1; i < n; i++) {
        pv = GCD(pv, v[i]);
    }
    return pv;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i=0; i<n; i++) cin >> r[i];
        for(int i=0; i<n; i++) cin >> p[i];
        int gcd = AllGCD(r, n);

        int mxk=gcd;
        for(int i=0; i<n; i++) {
            int k = (p[i]*gcd + r[i]-1)/r[i];
            mxk = max(mxk, k);
        }
        for(int i=0; i<n; i++) {
            printf("%lld ", (ll)(r[i]/gcd)*mxk-p[i]);
        }
        puts("");
    }
    return 0;
}