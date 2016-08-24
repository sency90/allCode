#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f;
int d[501][501], ans[501][501];
vector<pair<int,int> > v;
int main() {
    int V,E,s,e,w,x;
    scanf("%d%d", &V, &E);
    memset(d, 0x3f, sizeof(d));
    memset(ans, 0x3f, sizeof(ans));
    for(int i=1; i<=V; i++) {
        scanf("%d", &x);
        v.push_back(make_pair(x, i));
        d[i][i]=0; ans[i][i]=0;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<E; i++) {
        scanf("%d%d%d",&s,&e,&w);
        ans[s][e]=d[s][e]=min(d[s][e],w);
        ans[e][s]=d[e][s]=min(d[e][s],w);
    }

    for(int k=0; k<v.size(); k++) {
        int z = v[k].second;
        for(int i=1; i<=V; i++) {
            if(d[i][z]>=inf) continue;
            for(int j=1; j<=V; j++) {
                d[i][j] = min(d[i][j], d[i][z]+d[z][j]);
                ans[i][j] = min(ans[i][j], d[i][z]+d[z][j]+v[k].first);
            }
        }
    }
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d",&s,&e);
        printf("%d\n", ans[s][e]);
    }
    return 0;
}
