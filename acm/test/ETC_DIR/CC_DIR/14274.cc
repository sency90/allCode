#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> coy,co;
int cnt=0;
int ry[300001];
ll bit[300001], d[300001], c[300001];
void add(int i, ll by) {
    for(;i<=cnt;i+=i&-i) bit[i]+=by;
}
ll query(int i) {
    ll ret = 0ll;
    for(;i;i-=i&-i) ret+=bit[i];
    return ret;
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        coy.emplace_back(pii(y,i));
        co.emplace_back(pii(x,i));
    }
    sort(coy.begin(), coy.end());
    sort(co.begin(), co.end());
    for(auto &p: coy) ry[p.second]=++cnt;
    for(int i=0; i<n; i++) d[i]=c[i]=1ll;
    for(int i=n-1; i>=0; i--) {
        add(cnt-ry[co[i].second]+1,1);
        c[i]=query(cnt-ry[co[i].second]);
        if(c[i]==0) continue;
        c[i]=(c[i]*(c[i]-1))/2;
    }
    for(int len=2; len<=3; len++) {
        memset(bit,0,sizeof(bit));
        for(int i=0; i<n; i++) {
            add(ry[co[i].second],d[i]);
            d[i]=query(ry[co[i].second]-1);
        }
    }
    ll ans = 0ll;
    for(int i=0; i<n; i++) ans+=c[i]-d[i];
    printf("%lld\n",ans);
    return 0;
}
