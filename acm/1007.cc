#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
pii operator+(const pii &l, const pii &r) { return {l.first+r.first, l.second+r.second}; }

vector<pii> v;
int N,hN;
pii sum;
ll mn;

ll dist(pii x) { return (ll)x.first*x.first + (ll)x.second*x.second; }
void f(int k, int i, pii res) {
    if(k==N) {
        if(i==hN) mn=min(mn,dist(sum+res+res));
        return;
    }
    f(k+1,i,res);
    f(k+1,i+1,res+v[k]);
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        mn=inf;
        v.clear();
        scanf("%d",&N);
        hN=N>>1;
        int x,y,sx=0,sy=0;
        for(int i=0; i<N; i++) {
            scanf("%d%d",&x,&y);
            v.push_back({x,y});
            sx+=x; sy+=y;
        }
        sum = pii(-sx,-sy);
        f(0,0,{0,0});
        printf("%.6lf\n",sqrt(mn));
    }
    return 0;
}
