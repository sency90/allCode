#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int M = 1e9+7;
int Pow(int x, int n) {
    if(n==0) return 1;
    ll ret = Pow(x, n/2);
    ret *= ret;
    ret %= M;
    if(n%2==0) return ret;
    else return ret*x%M;
}
int main() {
    int n,r,M=1e9+7;
    cin >> n >> r;
    ll afact=1, rfact=1;
    for(int i=1, j=n; i<=r; i++, j--) {
        afact *= j;
        afact %= M;
        rfact *= i;
        rfact %= M;
    }
    //calc nCr % M
    printf("%lld\n", afact * Pow(rfact, M-2) % M);
    return 0;
}