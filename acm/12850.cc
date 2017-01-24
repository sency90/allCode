#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
vvl M(8, vl(8,0));
vvl E(8, vl(8,0));
const ll mod = 1e9+7;
void mkedge(int x, int y) {
    x--; y--;
    M[x][y]=M[y][x]=1;
}
void init() {
    mkedge(1,2); mkedge(1,3);
    mkedge(2,4); mkedge(2,3);
    mkedge(3,4); mkedge(3,5);
    mkedge(4,5); mkedge(4,6);
    mkedge(5,6); mkedge(5,7);
    mkedge(6,8); mkedge(7,8);
    for(int i=0; i<8; i++) E[i][i]=1;
}
vvl mul(vvl &A, vvl &B) {
    vvl ret(8, vl(8,0));
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            for(int k=0; k<8; k++) {
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
    int d; scanf("%d", &d);
    init();
    vvl ret = spow(M,d);
    printf("%lld", ret[0][0]%mod);
    return 0;
}
