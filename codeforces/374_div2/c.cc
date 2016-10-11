#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const long long inf = 1e18;
struct Edge{
    int t; long long w;
    Edge(){} Edge(int t, long long w):t(t),w(w){}
    bool operator<(const Edge &rhs) const { return w > rhs.w; }
};

vector<vector<Edge> > ed;
vector<long long> dist;
vector<bool> chk;
int p[5001][5001];
int cnt[5001];

long long dijkstra(int s, int e, int n, vector<vector<Edge> >& v) {
    priority_queue<Edge> mnh;
    chk.clear(); chk.resize(n+1, false);
    dist.clear(); dist.resize(n+1, inf);
    dist[s]=0LL;
    mnh.push(Edge(s,dist[s]));
    p[s][s]=s;

    Edge ed;
    for(int z=0; z<n; z++) {
        while(!mnh.empty()) {
            ed = mnh.top(); mnh.pop();
            if(!chk[ed.t]) break;
        }
        int x=ed.t;
        chk[x] = true;
        for(int i=v[x].size()-1; i>=0; i--) {
            int y = v[x][i].t;
            long long D = ed.w + v[x][i].w;
            if(chk[y]) continue;
            if(dist[y] > D) {
                dist[y] = D;
                p[s][y]=x;
                mnh.push(Edge(y,dist[y]));
            }
        }
    }
    cnt[s]=1;
    printf("test: 1 ");
    for(int i=p[s][e]; i!=s; i=p[s][i]) {
        cnt[s]++;
        printf("%d ", i);
    }
    printf("%d\n", s);
    return dist[e];
}
bool cmp(const pair<long long, int> &lhs, const pair<long long, int> &rhs) {
    if(lhs.first==rhs.first) return lhs.second<rhs.second;
    else return lhs.first>rhs.first;
}
vector<pair<long long, int> > ans;
int main() {
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    int u,v;
    long long w;
    ed.clear(); ed.resize(n+1, vector<Edge>());
    for(int i=0; i<m; i++) {
        scanf("%d%d%lld",&u,&v,&w);
        ed[u].push_back(Edge(v,w));
        ed[v].push_back(Edge(u,w));
    }
    long long tmp;
    for(int i=n; i>=2; i--) {
        tmp = dijkstra(i,1,n,ed);
        if(tmp<=t) ans.push_back(make_pair(cnt[i],i));
    }
    if(ans.empty()) {
        puts("1"); puts("1");
        return 0;
    }
    sort(ans.begin(), ans.end(), cmp);
    int ee=ans[0].second;
    printf("%d\n", cnt[ee]+1);
    printf("%d ", 1);
    for(int i=p[ee][1]; i!=ee; i=p[ee][i]) printf("%d ", i);
    printf("%d", ee);
    return 0;
}
