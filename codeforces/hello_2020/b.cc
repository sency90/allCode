#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
vector<int> g;
int main() {
    int n; scanf("%d", &n);
    int k=0;
    for(int i=0; i<n; i++) {
        int l; scanf("%d", &l);
        int px=-1;
        bool isAsc = false;
        int mn=0x3f3f3f3f, mx=-1;
        for(int j=0; j<l; j++) {
            int x; scanf("%d", &x);
            if(j!=0 && px<x) isAsc = true;
            mx = max(mx, x);
            mn = min(mn, x);
            px=x;
        }
        if(isAsc) k++;
        else v.emplace_back(mn,mx);
    }

    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        g.emplace_back(i);
    }

    sort(g.begin(), g.end());
    long long cnt = 0LL;
    for(int i=0; i<v.size(); i++) {
        auto it = upper_bound(g.begin(), g.end(), v[i].first);
        cnt += (long long)(g.end() - it);
    }
    cnt += (long long)(n-k+n-1)*k + k;
    printf("%lld", cnt);
    return 0;
}
