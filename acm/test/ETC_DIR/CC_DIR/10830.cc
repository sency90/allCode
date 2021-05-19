#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Mat;
Mat M, E;
const int MOD = 1000;
Mat mul(const Mat &X, const Mat &Y) {
    Mat ret(X.size(), vector<int>(X.size()));
    for(int i=0; i<X.size(); i++) {
        for(int j=0; j<X[i].size(); j++) {
            ret[i][j] = 0;
            for(int k=0; k<X.size(); k++) {
                ret[i][j] += X[i][k] * Y[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}
Mat f(const Mat &X, ll b) {
    if(b==0) return E;
    Mat ret = f(X, b/2);
    if(b%2LL==1LL) return mul(mul(ret,ret),X);
    else return mul(ret,ret);
}
int main() {
    int n; ll b;
    scanf("%d%lld", &n, &b);
    M.resize(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    E.resize(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) E[i][i] = 1;

    Mat res = f(M, b);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            printf("%d ", res[i][j]);
        }
        puts("");
    }
    return 0;
}
