#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<vector<ll>> matrix;
vector<pll> from,to,tower;
ll a,b,c,d,D;
matrix mk_inv_matrix(vector<pll>& tower) {
    matrix m(2, vector<ll>(2));
    for(int j=0; j<2; j++) {
        m[0][j] = (tower[j].X - tower[j+1].X)*2;
        m[1][j] = (tower[j].Y - tower[j+1].Y)*2;
    }
    a=m[0][0]; b=m[0][1]; c=m[1][0]; d=m[1][1];
    D = a*d-b*c;

    swap(m[0][0], m[1][1]);
    m[0][1]*=-1;
    m[1][0]*=-1;

    return m;
}
int main() {
    int n;
    ll x,y;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld%lld",&x,&y);
        from.push_back({x,y});
    }
    for(int i=0; i<n; i++) {
        scanf("%lld%lld",&x,&y);
        to.push_back({x,y});
    }
    for(int i=0; i<3; i++) {
        scanf("%lld%lld",&x,&y);
        tower.push_back({x,y});
    }
    matrix inv = mk_inv_matrix(tower);

    int end=0;
AGAIN:
    sort(from.begin(), from.end());
    sort(to.begin(), to.end());
    auto minus = [&](int i) { return pll(to[i].X-from[i].X, to[i].Y-from[i].Y); };
    pll dif = minus(0);

    bool good=true;
    for(int i=0; good && i<n; i++) {
        if(dif != minus(i)) good=false;
    }

    if(D==0) {
        ll p=dif.X, q=dif.Y;
        if(good) {
            if(p==0 && q==0) good=true;
            else {
                good=false;
                auto chk = [&](ll x, ll y) {
                    ll j = (b!=0)?x/b:y/d;
                    return (x==b*j) && (y==d*j);
                };
                for(ll i=-1000000; i<=1000000; i++) {
                    if(chk(p-a*i,q-c*i)) {
                        good=true;
                        break;
                    }
                }
            }
        }
    } else {
        for(int i=0; good && i<2; i++) {
            if(ll(inv[i][0]*dif.X+inv[i][1]*dif.Y)%D != 0) good=false;
        }
    }

    if(good) return 0&puts("1");
    else {
        if(end++) return 0&puts("0");
        for(int i=0; i<n; i++) {
            for(int j=0; j<3; j++) {
                from[i].X = 2*tower[j].X - from[i].X;
                from[i].Y = 2*tower[j].Y - from[i].Y;
            }
        }
        goto AGAIN;
    }
    return 0;
}
