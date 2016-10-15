#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef pair<int,int> pii;
vector<pair<int, pii> > v;
int dist[501];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v.push_back(make_pair(w,make_pair(x,y)));
    }
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    for(int i=1; i<=n; i++) {
        for(auto &p: v) {
            int x=p.second.first, y=p.second.second, w=p.first;
            //아래의 inf체크가 반드시 이뤄져야 함.
            if(dist[x]>=inf) continue;
            if(dist[y]>dist[x]+w) {
                dist[y]=dist[x]+w;
                //음수 사이클 생기면 -1 출력하고 종료
                if(i==n) { puts("-1"); return 0; }
            }
        }
    }
    //if dist[x]==inf => print(-1)
    for(int i=2; i<=n; i++) printf("%d\n", dist[i]<inf?dist[i]:-1);
    return 0;
}
