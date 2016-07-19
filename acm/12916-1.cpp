#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long> > matrix;
const long long MOD = 1000000007LL;
matrix A,E;

matrix operator*(const matrix& lhs, const matrix& rhs) {
    int n=lhs.size();
    matrix ret(n, vector<long long>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                ret[i][j] = (ret[i][j] + lhs[i][k] * rhs[k][j])%MOD;
            }
        }
    }
    return ret;
}

long long ms(long long x, long long y) {
    return (x+y)>=MOD?x+y-MOD:x+y;
}

matrix f(matrix& mat, int x) {
    if(x==0) return E;
    matrix ret = f(mat,x/2);
    ret = ret*ret;
    if(x%2) ret = ret*A;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    A.resize(n, vector<long long>(n));
    E.resize(n, vector<long long>(n,0LL));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
            if(i==j) E[i][j]=1;
        }
    }
    A = f(A, k);
    long long sum = 0LL;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sum = ms(sum,A[i][j]);
        }
    }
    cout << sum;
    return 0;
}
