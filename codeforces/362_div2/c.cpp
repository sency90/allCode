#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
struct Edge {
    long long n,w;
    Edge() {};
    Edge(long long nn, long long ww) {n=nn;w=ww;};
    bool operator<(const Edge& rhs) const { //for minhea;
        //if(w == rhs.w) return n > rhs.n;
        //else
        return w > rhs.w;
    }
};
map<long long, vector<Edge> > v;
map<long long, bool> chk;
map<long long, long long> dist;

int main() {
    int q,type;
    long long s,e,w;
    scanf("%d", &q);
    while(q--) {
        scanf("%d%lld%lld",&type,&s,&e);
        if(type == 1) {
            scanf("%lld", &w);
            v[s].push_back(Edge(e,w));
            v[e].push_back(Edge(s,w));
        } else {
            chk.clear();
            dist.clear();
            priority_queue<Edge> mnh;
            mnh.push(Edge(s,0));
            dist[s]=0;

            Edge ed;
            int n = v.size();
            for(int i=0; i<n; i++) {
                while(!mnh.empty()) {
                    ed = mnh.top(); mnh.pop();
                    if(chk.count(ed.n)==0) break;
                }

                s = ed.n;
                chk[s] = true;
                for(int j=0; j<v[s].size(); j++) {
                    e = v[s][j].n; w = v[s][j].w;
                    if(chk.count(e)>0) continue;
                    if(dist.count(e)==0) dist[e]=0x3f3f3f3f;
                    if(dist[e] > dist[s]+w) {
                        dist[e] = dist[s]+w;
                        mnh.push(Edge(e, dist[e]));
                    }
                }
            }
            printf("%lld\n", dist[e]);
        }
    }
    return 0;
}
