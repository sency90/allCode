#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Rect {
    ll x1,y1,x2,y2;
    Rect() {}
    Rect(ll a,ll b,ll c,ll d) :x1(a),y1(b),x2(c),y2(d) {}
};
vector<Rect> rect;
int d[5000];
bool cmp(const Rect &l,const Rect &r) {
    return l.x1<=r.x1&&l.x2>=r.x2&&l.y1<=r.y1&&l.y2>=r.y2;
}
bool cmp2(const Rect &l,const Rect &r) {
    return (l.x2-l.x1)*(l.y2-l.y1)<(r.x2-r.x1)*(r.y2-r.y1);
}
int main() {
    setbuf(stdout,NULL);
    freopen("input.txt","r",stdin);
    int tc; scanf("%d",&tc);
    for(int z=1; z<=tc; z++) {
        rect.clear();
        memset(d,0,sizeof(d));
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<k; i++) {
            ll x1,y1,x2,y2;
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            rect.push_back(Rect(x1,y1,x2,y2));
        }
        sort(rect.begin(),rect.end(),cmp2);
        int mx=0;
        for(int i=1; i<k; i++) {
            for(int j=i-1; j>=0; j--) {
                if(cmp(rect[i],rect[j])) d[i]=max(d[i],d[j]+1);
            }
            mx=max(mx,d[i]);
        }
        printf("Case #%d\n%d\n",z,mx+1);
    }
    return 0;
}
