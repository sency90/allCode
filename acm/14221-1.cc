#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int dist[5001];
bool h[5001], chk[5001];
vector<pii> v[5001];
priority_queue<pii, vector<pii>, greater<pii>> mnh;
int main() {
    memset(dist,0x3f,sizeof(dist));
    memset(h,false,sizeof(h));
    int n,m; scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].emplace_back(pii(w,y));
        v[y].emplace_back(pii(w,x));
    }
    int p,q; scanf("%d%d",&p,&q);
    for(int i=0; i<p; i++) {
        int x; scanf("%d", &x);
        h[x]=true;
    }
    for(int i=0; i<q; i++) {
        int x; scanf("%d", &x);
        dist[x]=0; mnh.push(pii(0,x));
    }

    pii tmp;
    for(int z=0; z<n; z++) {
        while(!mnh.empty()) {
            tmp = mnh.top(); mnh.pop();
            if(!chk[tmp.second]) break;
        }
        int x=tmp.second;
        chk[x]=true;
        for(int i=0; i<v[x].size(); i++) {
            int y=v[x][i].second, w=v[x][i].first;
            if(chk[y]) continue;
            if(dist[y]>dist[x]+w) {
                dist[y]=dist[x]+w;
                mnh.push(pii(dist[y],y));
            }
        }
    }
    int mn=0x3f3f3f3f, ans=0;
    for(int i=1; i<=n; i++) {
        if(h[i] && mn>dist[i]) {
            mn=dist[i];
            ans=i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
