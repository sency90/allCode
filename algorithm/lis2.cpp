#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int,int>;
int v[100001];
int prv[100001];
vector<pii> g;
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    g.emplace_back(-1,0);
    for(int i=1; i<=n; i++) {
        auto it = lower_bound(g.begin(), g.end(), pii(v[i],0));
        prv[i] = (it-1)->second;

        if(it == g.end()) g.emplace_back(v[i],i);
        else *it = pii(v[i],i);
    }
    for(int i=0; i<g.size(); i++) {
        printf("%d,%d\n", g[i].first, g[i].second);
    }
    for(int i=1; i<=n; i++) {
        printf("prev[%d]: %d\n", i, prv[i]);
    }
    for(int i=g.back().second;i!=0;i=prv[i]) {
        printf("%d ", v[i]);
    }
    puts("");
    return 0;
}
