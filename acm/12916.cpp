#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<vector<long long> > matrix;
const long long MOD = 1000000007LL;
matrix e;

matrix operator*(const matrix &lhs, const matrix &rhs) {
    int n = lhs.size();
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

matrix spow(matrix& A, long long k) {
    if(k==0) return e;
    matrix ret = spow(A, k/2);
    ret = ret*ret;
    if(k%2) ret = ret*A;
    return ret;
}

int main() {
    long long n, k;
    scanf("%lld%lld", &n,&k);

    e.resize(n, vector<long long>(n,0LL));
    for(int i=0; i<n; i++) e[i][i]=1LL;

    matrix A(n, vector<long long>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%lld", &A[i][j]);
        }
    }

    matrix ans = spow(A, k);
    long long sum = 0LL;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sum = (sum+ans[i][j])%MOD;
        }
    }
    printf("%lld", sum);
    return 0;
}
