#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pii> co;
map<int, int> mp;
int dist(pii &a, pii &b) {
    int x=a.first-b.first, y=a.second-b.second;
    return x*x+y*y;
}
int d[2001][3];
int combi(int n, int r) {
    int &ret = d[n][r];
    if(ret>=0) return ret;
    if(n==r||r==0) return ret=1;
    else if(n<r) return ret=0;
    return ret = combi(n-1,r-1)+combi(n-1,r);
}
int main() {
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    memset(d,-1,sizeof(d));
    for(int z=1; z<=tc; z++) {
        int ans=0,n,x,y;
        co.clear();
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d%d",&x,&y);
            co.push_back({x,y});
        }
        for(int i=0; i<n; i++) {
            mp.clear();
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                mp[dist(co[i],co[j])]++;
            }
            for(auto &p: mp) {
                ans+=combi(p.second,2);
            }
        }
        printf("Case #%d: %d\n", z, ans);
    }
    return 0;
}
