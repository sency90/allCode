#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge {
    int n;
    long long w;
    Edge() {};
    Edge(int nn, long long ww) {n=nn;w=ww;};
    bool operator<(const Edge& rhs) const { //for minhea;
        if(w == rhs.w) return n > rhs.n;
        else return w > rhs.w;
    }
};
vector<vector<Edge> > v;
bool chk[100001];
long long dist[100001];
int src[100001];

int main() {
    int t;
    setbuf(stdout, NULL);
    scanf("%d", &t);
    for(int z=1; z<=t; z++) {
        printf("Case #%d\n", z);

        int n, m, k;
        scanf("%d%d%d",&n,&m,&k);

        int s, e;
        long long w;
        v.clear();
        v.resize(n+1);
        for(int i=0; i<m; i++) {
            scanf("%d%d%lld",&s,&e,&w);
            v[s].push_back(Edge(e,w));
            v[e].push_back(Edge(s,w));
        }

        int x;
        memset(chk, false, sizeof(chk));
        memset(dist, 0x3f, sizeof(dist));
        priority_queue<Edge> mnh;
        for(int i=0; i<k; i++) {
            scanf("%d", &x);
            dist[x] = 0LL;
            src[x] = x;
            mnh.push(Edge(x,0));
        }

        Edge ed;
        for(int i=0; i<n; i++) {
            while(!mnh.empty()) {
                ed = mnh.top(); mnh.pop();
                if(!chk[ed.n]) break;
            }

            s = ed.n;
            chk[s] = true;
            for(int j=0; j<v[s].size(); j++) {
                e = v[s][j].n; w = v[s][j].w;
                if(chk[e]) continue;
                if(dist[e] > dist[s]+w) {
                    dist[e] = dist[s]+w;
                    src[e] = src[s];
                    mnh.push(Edge(e, dist[e]));
                }
            }
        }

        long long s1=0;
        int s2=0;
        for(int i=1; i<=n; i++) {
            s1+=dist[i];
            s2+=src[i];
        }
        printf("%lld\n%d\n",s1,s2);
    }
    return 0;
}
