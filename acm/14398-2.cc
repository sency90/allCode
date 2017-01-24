#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
vector<int> v[201];
int aMatch[201],bMatch[201], in[201];
bool chk[201];
bool bipartite(int x) {
    if(chk[x]) return false;
    chk[x]=true;
    for(auto &y: v[x]) {
        if(!bMatch[y]||bipartite(bMatch[y])) {
            aMatch[x]=y;
            bMatch[y]=x;
            return true;
        }
    }
    return false;
}
ll valid(ll x, ll y) {
    if(x>y) swap(x,y);
    double res = sqrt(x*x+y*y);
    ll res2 = res;
    if(res == (double)res2) return true;
    res = sqrt(y*y-x*x);
    res2 = int(res);
    if(res == (double)res2) return true;
    else return false;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &in[i]);
    }

    sort(in, in+n);
    int l,r;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(in[i]!=in[j]) {
                if(valid(in[i],in[j])) {
                    //if(in[i]<in[j]) l=i,r=j;
                    //else l=j,r=i;
                    v[i].push_back(j);
                }
            }
        }
    }

    memset(aMatch,0,sizeof(aMatch));
    memset(bMatch,0,sizeof(bMatch));
    int ans=0;
    for(int i=0; i<n; i++) {
        memset(chk, false, sizeof(chk));
        if(bipartite(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
