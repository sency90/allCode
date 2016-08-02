#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long> > matrix;
typedef long long ll;
const ll MOD = 1000000007LL;
matrix A,E;
matrix operator*(const matrix &lhs, const matrix &rhs) {
    int n = lhs.size();
    matrix ret(n, vector<ll>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                ret[i][j] = (ret[i][j] + lhs[i][k]*rhs[k][j])%MOD;
            }
        }
    }
    return ret;
}
matrix spow(matrix &M, int k) {
    if(k==0) return E;
    matrix ret = spow(M, k/2);
    return (k%2)?ret*ret*A:ret*ret;
}
ll ms(ll x, ll y) {
    return x+y>=MOD? x+y-MOD : x+y;
}
int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    A.resize(n, vector<ll>(n));
    E.resize(n, vector<ll>(n,0));
    for(int i=0; i<n; i++) {
        E[i][i]=1LL;
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }
    ll sum = 0LL;
    matrix ANS = spow(A,k);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sum = ms(sum,ANS[i][j]);
        }
    }
    cout << sum;
    return 0;
}
