#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
class pn{
    public:
        int node,dist,cost;//현재 정점 , 현재 까지 이동한 거리 , 든 비용
        pn(int a,int b,int c):node(a),dist(b),cost(c){}
        bool operator<(const pn& b)const{
            return dist > b.dist;
        }
};

class ed{
    public:
        int node,dist,cost;
        ed(int a,int b,int c):node(a),dist(b),cost(c){}
};

priority_queue <pn> pq;

const int N = 105;
const int K = 10005;
const int INF = 0x3f3f3f3f;
int dist[N][K];
int k,n,r;

vector < vector < ed > > adj;
bool chk[K];

int dijkstra(){
    memset(dist, 0x3f, sizeof(dist));

    dist[1][0] = 0;
    pq.push(pn(1,0,0));
    //node , dist, cost
    pn now(0,0,0);
    for(int i=0; i<N; i++) {
        while(!pq.empty()){
            now = pq.top(); pq.pop();
            if(!chk[now.node]) break;
        }
        chk[now.node] = true;
        for(int i = 0;i<adj[now.node].size();++i){
            ed& next = adj[now.node][i];
            if(chk[next.node]) continue;
            if(now.cost + next.cost > k)continue;
            if(dist[next.node][now.cost + next.cost] <= dist[now.node][now.cost]+next.cost)continue;
            dist[next.node][now.cost + next.cost] = dist[now.node][now.cost] + next.dist;
            pq.push(pn(next.node,dist[next.node][now.cost+next.cost],now.cost + next.cost));
        }
    }
    int ret = INF;
    for(int i=0;i<=k;++i){
        ret = min(ret,dist[n][i]);
    }
    if(ret==INF)return -1;
    else return ret;
}

int main(){
    scanf("%d%d%d",&k,&n,&r);
    adj.resize(n+1);
    for(int i=0;i<r;++i){
        int x,y,d,c;
        scanf("%d%d%d%d",&x,&y,&d,&c);
        adj[x].push_back(ed(y,d,c));
    }
    int ans = dijkstra();
    printf("%d\n",ans);
    return 0;
}
