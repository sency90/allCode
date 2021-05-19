#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
vvl M, E;
const ll mod = 1e9+7;
void mkedge(int x, int y) {
    x--; y--;
    M[x][y]=M[y][x]=1;
}
vvl mul(vvl &A, vvl &B) {
    int n = A.size();
    vvl ret(n, vl(n,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                ret[i][j] += A[i][k]*B[k][j];
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}
vvl spow(vvl &A, int d) {
    if(d==0) return E;
    vvl ret = spow(A,d/2);
    if(d&1) {
        vvl tmp = mul(ret,ret);
        return mul(tmp,A);
    } else return mul(ret,ret);
}
int main() {
    int n, m; scanf("%d%d",&n,&m);
    E.resize(n, vl(n,0));
    for(int i=0; i<n; i++) E[i][i]=1;
    M.resize(n, vl(n,0));
    for(int i=0; i<m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        mkedge(x,y);
    }
    int d; scanf("%d", &d);
    vvl ret = spow(M,d);
    printf("%lld", ret[0][0]%mod);
    return 0;
}
