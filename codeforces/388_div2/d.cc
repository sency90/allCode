#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
vector<int> v[200001];
set<pii> mx;
queue<int> q;
int main() {
    int n,a,b;
    scanf("%d", &n);
    v[0].push_back(0);
    int mxpno=0;
    for(int i=1; i<=n; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        mxpno=max(a,mxpno);
    }
    for(int i=1; i<=mxpno; i++) {
        if(v[i].empty()) continue;
        mx.insert({v[i].back(),i});
    }
    int Q; scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        int k; scanf("%d", &k);
        for(int j=0; j<k; j++) {
            int l; scanf("%d", &l);
            if(v[l].empty()) continue;
            q.push(l);
            mx.erase({v[l].back(),l});
        }
        if(mx.empty()) puts("0 0");
        else {
            auto it = mx.end();
            if(--it == mx.begin()) {
                printf("%d %d\n",it->second,v[it->second][0]);
            } else {
                int x = it--->second;
                auto jt = lower_bound(v[x].begin(),v[x].end(),v[it->second].back());
                printf("%d %d\n", x, *jt);
            }

        }
        while(!q.empty()) {
            int x=q.front(); q.pop();
            mx.insert({v[x].back(),x});
        }
    }
    return 0;
}
