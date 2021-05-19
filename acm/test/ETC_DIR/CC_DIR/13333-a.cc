#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
//bool cmp(int i, int j) { return i>j; }
int mx = 0;
int main() {
    int n; scanf("%d",&n);
    v.clear(); v.resize(n);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for(int k: v) {
        auto it = lower_bound(v.begin(), v.end(), k);
        int l=v.end()-it;
        if(l>=k) mx = max(mx,k);
    }
    printf("%d\n", mx);
    return 0;
}
