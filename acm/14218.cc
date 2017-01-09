//Undirected Graph
//Dijkstra Algorithm using binary heap
//O((E+V)lgV)

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int inf = 6250001;
struct Edge{
	int t; int w;
	Edge(){} Edge(int t, int w):t(t),w(w){}
	bool operator<(const Edge &rhs) const { return w > rhs.w; }
};

vector<vector<Edge> > ed;
vector<int> dist;
vector<bool> chk;

void dijkstra(int s, int n, vector<vector<Edge> >& v) {
	priority_queue<Edge> mnh;
	chk.clear(); chk.resize(n+1, false);
	dist.clear(); dist.resize(n+1, inf);
	dist[s]=0;
	mnh.push(Edge(s,dist[s]));

	Edge ed;
	for(int z=0; z<n; z++) {
		while(!mnh.empty()) {
			ed = mnh.top(); mnh.pop();
			if(!chk[ed.t]) break;
		}
		int x=ed.t;
		chk[x] = true;
		for(int i=0; i<v[x].size(); i++) {
			int y = v[x][i].t;
			int D = ed.w + v[x][i].w;
			if(chk[y]) continue;
			if(dist[y] > D) {
				dist[y] = D;
				mnh.push(Edge(y,dist[y]));
			}
		}
	}

    for(int i=1; i<=n; i++) {
        if(dist[i]>=inf) printf("-1 ");
        else printf("%d ", dist[i]);
    }
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m); //n: number of verties, m: number of edges
	ed.clear(); ed.resize(n+1, vector<Edge>());
	int u,v;
	for(int i=0; i<m; i++) {
		scanf("%d%d",&u,&v);
		ed[u].push_back(Edge(v,1));
		ed[v].push_back(Edge(u,1));
	}
	int q; scanf("%d", &q);
	for(int i=0; i<q; i++) {
		scanf("%d%d",&u,&v);
        ed[u].push_back(Edge(v,1));
        ed[v].push_back(Edge(u,1));
		dijkstra(1,n,ed);
        puts("");
	}
	return 0;
}
