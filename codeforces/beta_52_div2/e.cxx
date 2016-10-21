#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pair<pair<int,int>, int> > pos;
vector<int> x;
int ans[100001];
int main() {
    int n; scanf("%d", &n);
    x.resize(n);
    for(int i=0; i<n; i++) {
        int h;
        scanf("%d%d",&x[i],&h);
        pos.push_back(make_pair(make_pair(x[i],x[i]+h),i));
    }
    sort(x.begin(),x.end());
    sort(pos.begin(), pos.end());
    for(auto &p: pos) {
        auto it = lower_bound(pos.begin(), pos.end(), pair<pii,int>(pii(p.first.second, 0),0));
        ans[p.second]=pos[it-pos.begin()].second-p.second;
    }
    for(int i=0; i<n; i++) printf("%d ", ans[i]);
    return 0;
}
