#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v[20001];
priority_queue<pii, vector<pii>, greater<pii>> mnh;
int dist[20001];
bool chk[20001];
const int inf = 0x3f3f3f3f;
int main() {
    int n,m,start;
    scanf("%d%d%d",&n,&m,&start);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].emplace_back(pii(w,y));
    }
    memset(dist,0x3f,sizeof(dist));
    mnh.push(pii(0,start));
    dist[start]=0;
    while(!mnh.empty()) {
        pii tmp = mnh.top(); mnh.pop();
        int d=tmp.first, x=tmp.second;
        if(chk[x]) continue;
        chk[x]=true;
        for(pii &t: v[x]) {
            int w=t.first, y=t.second;
            if(chk[y]) continue;
            if(dist[y]>d+w) {
                dist[y]=d+w;
                mnh.push(pii(dist[y],y));
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(dist[i]>=inf) puts("INF");
        else printf("%d\n", dist[i]);
    }
    return 0;
}
