#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
vector<int> v[201];
int aMatch[201],bMatch[201],in[201];
bool chk[201];
bool bipartite(int x) {
    if(chk[x]) return false;
    chk[x]=true;
    for(int y: v[x]) {
        if(bMatch[y]==-1||bipartite(bMatch[y])) {
            aMatch[x]=y;
            bMatch[y]=x;
            return true;
        }
    }
    return false;
}
bool valid(ll x, ll y) {
    long long c = x*x+y*y;
    long long res = sqrt(c);
    if(c==res*res) return true;
    if(c==(res+1)*(res+1)) return true;
    if(c==(res-1)*(res-1)) return true;
    return false;
}
int gcd(int b, int s) { return (s==0)?b:gcd(s,b%s); }
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &in[i]);

    sort(in+1,in+n+1);
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(in[i]!=in[j]) {
                if(valid(in[i],in[j]) && gcd(in[i],in[j])==1) {
                    if(in[i]&1) v[i].push_back(j);
                    else v[j].push_back(i);
                }
            }
        }
    }

    memset(aMatch,-1,sizeof(aMatch));
    memset(bMatch,-1,sizeof(bMatch));
    int ans=0;
    for(int i=1; i<=n; i++) {
        memset(chk, false, sizeof(chk));
        if(bipartite(i)) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
