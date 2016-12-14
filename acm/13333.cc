#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int n; scanf("%d",&n);
    v.clear(); v.resize(n);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for(int k=0; k<=n; k++) {
        auto it = lower_bound(v.begin(), v.end(), k);
        int l=v.end()-it;
        if(l>=k && v[n-k-1]<=k) return 0&printf("%d\n", k);
    }
    return 0;
}
