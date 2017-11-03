#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
vector<pii> sort(vector<pii> &v) {
    int n=v.size();
    vector<pii> ret(n);
    vector<int> cnt(n+1,0);
    vector<int> idx(n,0);

    for(int i=0; i<n; i++) cnt[v[i].second]++;
    for(int i=1; i<=n; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) idx[--cnt[v[i].second]]=i;

    cnt.clear(); cnt.resize(n+1,0);
    for(int i=0; i<n; i++) cnt[v[i].first]++;
    for(int i=1; i<=n; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) ret[--cnt[v[idx[i]].first]]=v[idx[i]];

    return ret;
}
int main() {
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int x,y; scanf("%d%d",&x,&y);
        assert(x>=1 && x<=n && y>=1 && y<=n);
        v.push_back(pii(x,y));
    }
    vector<pii> ans = sort(v);
    for(int i=0; i<n; i++) {
        int x=ans[i].first, y=ans[i].second;
        printf("%d %d\n",x,y);
    }
    return 0;
}
