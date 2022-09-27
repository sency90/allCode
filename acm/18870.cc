#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using pii = pair<int,int>;
vector<pii> v;
int ans[1000001];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v.emplace_back(x,i);
    }

    sort(v.begin(), v.end());
    int pv = -1e9-1;
    int idx = -1;
    for(int i=0; i<n; i++) {
        if(pv != v[i].first) idx++;
        ans[v[i].second] = idx;
        pv = v[i].first;
    }

    for(int i=0; i<n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
