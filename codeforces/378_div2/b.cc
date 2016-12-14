#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
int main() {
    int n,l,r,lval=0,rval=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&l,&r);
        v.push_back({l,r});
        lval+=l; rval+=r;
    }
    int mx=max(lval,rval);
    int mxori=mx, ans=0;
    for(int i=0; i<n; i++) {
        int mxtmp = mx;
        mx = max({mx,lval-v[i].first+v[i].second,rval-v[i].second+v[i].first});
        if(mx!=mxtmp) ans=i+1;
    }
    if(mx==mxori) puts("0");
    else printf("%d", ans);
    return 0;
}
