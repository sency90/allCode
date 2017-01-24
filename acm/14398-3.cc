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
        if(chk[bMatch[y]]) continue; //안써도 된다. chk[y]로 쓰지 않도록 주의할 것.
        if(!bMatch[y]||bipartite(bMatch[y])) {
            aMatch[x]=y;
            bMatch[y]=x;
            return true;
        }
    }
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &in[i]);
    }

    auto valid = [&](ll x, ll y) {
        if(y<x) swap(x,y);
        ll c = x*x+y*y;
        ll res = sqrt(c);
        int dx[]={0,1,-1};
        for(int i=0; i<3; i++) {
            if(c==(res+dx[i])*(res+dx[i])) return true;
        }
        c=y*y-x*x;
        res=sqrt(c);
        for(int i=0; i<3; i++) {
            if(c==(res+dx[i])*(res+dx[i])) return true;
        }
        return false;
    };

    sort(in+1,in+n+1);
    int l,r;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(in[i]!=in[j]) {
                if(valid(in[i],in[j])) {
                    if(in[i]&1) l=i,r=j;
                    else l=j, r=i;
                    v[l].push_back(r);
                }
            }
        }
    }

    memset(aMatch,0,sizeof(aMatch));
    memset(bMatch,0,sizeof(bMatch));
    int ans=0;
    for(int i=1; i<=n; i++) {
        memset(chk, false, sizeof(chk));
        if(bipartite(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
