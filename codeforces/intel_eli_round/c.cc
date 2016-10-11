#include <cstdio>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
set<pair<int,int> > seg;
map<ll,int> candi;
ll psum[100001];
int main() {
    int n,t;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &t);
        psum[i]=psum[i-1]+t;
    }
    int o;
    seg.insert(pii(n,0));
    candi[psum[n]-psum[0]]++;
    for(int i=1; i<=n; i++) {
        scanf("%d", &o);
        auto it = seg.lower_bound(pii(o,0));
        pii tmp = *it;
        seg.erase(it);
        seg.insert(pii(tmp.first,o));
        seg.insert(pii(o-1,tmp.second));

        ll pans = psum[tmp.first]-psum[tmp.second];
        auto it2 = candi.lower_bound(pans);
        if(--candi[it2->first] == 0) candi.erase(it2);
        candi[psum[tmp.first]-psum[o]]++;
        candi[psum[o-1]-psum[tmp.second]]++;

        auto ans = candi.end();
        ans--;
        printf("%lld\n",ans->first);
    }
    return 0;
}
