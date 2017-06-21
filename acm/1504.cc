#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
priority_queue<pii, vector<pii>, greater<pii>> mnh;
vector<pii> v[801];
int dist[801],chk[801];
const int inf = 0x3f3f3f3f;
int n,m;
int CC=1;
void dijkstra(int s) {
    memset(dist,0x3f,sizeof(dist));
    int sz=mnh.size();
    for(int i=0; i<sz; i++) mnh.pop();

    CC++;
    dist[s]=0;
    mnh.push(pii(0,s));
    pii tmp;
    for(int i=0; i<n; i++) {
        while(!mnh.empty()) {
            tmp = mnh.top(); mnh.pop();
            if(chk[tmp.second]<CC) break;
        }
        int x=tmp.second, d=tmp.first;
        chk[x]=CC;
        for(pii &t: v[x]) {
            int y=t.second, w=t.first;
            if(chk[y]==CC) continue;
            if(dist[y]>d+w) {
                dist[y]=d+w;
                mnh.push(pii(dist[y],y));
            }
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].emplace_back(pii(w,y));
        v[y].emplace_back(pii(w,x));
    }
    int p,q;
    scanf("%d%d",&p,&q);
    dijkstra(1);
    int dist_1top=dist[p];
    int dist_1toq=dist[q];
    dijkstra(p);
    int dist_ptoq=dist[q];
    int dist_pton=dist[n];
    dijkstra(q);
    int dist_qton=dist[n];
    ll lh=(ll)dist_1top+dist_ptoq+dist_qton;
    ll rh=(ll)dist_1toq+dist_ptoq+dist_pton;
    ll ans = min(lh,rh);
    if(ans>=inf) puts("-1");
    else printf("%lld", ans);
    return 0;
}
