#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pii> co,s;
int cnt[100001], c[100001];
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        co.emplace_back(pii(x,y));
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &c[i]);
    }
    for(int i=0; i<co.size(); i++) {
        if(c[co[i].first]!=c[co[i].second]) {
            s.push_back(co[i]);
        }
    }
    if(s.empty()) return 0&printf("YES\n%d\n", co[0].first);

    int r1=s[0].first, r2=s[0].second;
    for(auto &p: s) {
        if(r1!=p.first && r1!=p.second) r1=0;
        if(r2!=p.first && r2!=p.second) r2=0;
    }
    if(r1) printf("YES\n%d\n", r1);
    else if(r2) printf("YES\n%d\n", r2);
    else puts("NO");
    return 0;
}
