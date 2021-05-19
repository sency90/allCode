#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct Info{
    int v,c,d;
    Info(){}
    Info(int v, int c, int d):v(v),c(c),d(d) {}
    bool operator<(const Info & rhs) const {
        if(d == rhs.d) return c>rhs.c;
        else return d>rhs.d;
    }
};
int chk[101][10001], dist[101][10001];
vector<vector<Info>> list;
priority_queue<Info> mnh;
int main() {
    int tc,n,m,k,u,v,c,d;
    scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        scanf("%d%d%d",&n,&m,&k);
        list.clear(); list.resize(n+1, vector<Info>());
        memset(dist, 0x3f, sizeof(dist));
        for(int i=0; i<k; i++) {
            scanf("%d%d%d%d",&u,&v,&c,&d);
            list[u].emplace_back(v,c,d);
        }

        bool hasAns = false;
        mnh.emplace(1,0,0);
        Info cur;

        dist[1][0]=0;
        while(!mnh.empty()) {
            cur = mnh.top(); mnh.pop();
            if(chk[cur.v][cur.c] == z) continue;
            chk[cur.v][cur.c] = z;

            if(cur.v==n) {
                hasAns = true;
                printf("%d\n", cur.d);
                break;
            }
            for(int i=0; i<list[cur.v].size(); i++) {
                const Info & next = list[cur.v][i];
                if(cur.c + next.c > m) continue;
                if(dist[next.v][cur.c+next.c] <= dist[cur.v][cur.c] + next.d) continue;
                dist[next.v][cur.c+next.c] = dist[cur.v][cur.c] + next.d;
                mnh.emplace(next.v, cur.c+next.c, dist[next.v][cur.c+next.c]);
            }
        }
        while(!mnh.empty()) mnh.pop();

        if(!hasAns) puts("Poor KCM");
    }
    return 0;
}
