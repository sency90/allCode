#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
int d[10001];
int main() {
    int n,w; scanf("%d%d",&n,&w);
    for(int i=0; i<n; i++) {
        int wei,val;
        scanf("%d%d", &wei,&val);
        v.push_back(pii(wei,val));
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=w; j>=v[i].first; j--) {
            d[j] = max(d[j-v[i].first] + v[i].second, d[j]);
            ans = max(d[j],ans);
        }
    }
    printf("%d\n", ans);
    return 0;
}
