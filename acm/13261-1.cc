#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
ll v[8001], d[801][8001], p[801][8001], psum[8001];
void solve(int g, int l, int r, int pl, int pr) {
    if(l>r) return;
    int mid = (l+r)>>1;
    p[g][mid]=-1;
    d[g][mid] = inf;
    for(int k=pl; k<=pr && k<=mid; k++) {
        ll tmp = d[g-1][k] + (psum[mid]-psum[k])*(mid-k);
        if(d[g][mid] > tmp) {
            d[g][mid] = tmp;
            p[g][mid] = k;
        }
    }
    solve(g,l,mid-1,pl,p[g][mid]);
    solve(g,mid+1,r,p[g][mid],pr);
}
int main() {
    int L,G;
    scanf("%d%d",&L,&G);
    memset(p,0x3f,sizeof(p));
    for(int i=1; i<=L; i++) {
        scanf("%lld", &v[i]);
        psum[i]=psum[i-1]+v[i];
    }
    for(int i=1; i<=L; i++) {
        d[1][i] = (psum[i]-psum[0])*i;
        p[1][i] = 0;
    }
    for(int g=2; g<=G; g++) {
        solve(g, 0,L, 0,L);
    }
    printf("%lld", d[G][L]);
    return 0;
}
