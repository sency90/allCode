#include <iostream>
using namespace std;
const long long MOD = 1000000007LL;
int n, k;
long long **A, **E;
long long** mul(long long** lhs, long long** rhs) {
    long long** ret = new long long*[n];
    for(int i=0; i<n; i++) {
        ret[i] = new long long[n];
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                ret[i][j] = (ret[i][j] + lhs[i][k]*rhs[k][j])%MOD;
            }
        }
    }
    return ret;
}

long long** spow(long long** A, int k) {
    if(k==0) return E;
    long long** ret = spow(A, k/2);
    return ret = (k%2)? mul(mul(ret,ret),A) : mul(ret,ret);
}

long long ms(long long x, long long y) {
    return x+y>=MOD?x+y-MOD:x+y;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    A = new long long*[n];
    E = new long long*[n];
    for(int i=0; i<n; i++) {
        A[i] = new long long[n];
        E[i] = new long long[n];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
            if(i==j) E[i][j]=1LL; //1LL이 아니라 1쓰면 ERROR!!!!!
        }
    }
    long long** ans = spow(A, k);
    long long sum = 0LL;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sum = ms(sum,ans[i][j]);
        }
    }
    cout << sum;
    return 0;
}
