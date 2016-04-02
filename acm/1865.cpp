#include <stdio.h>
#include <cstring>
#include <limits.h>
using namespace std;
int d[501];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int inf = 100000000;
struct Edge{
    int s, e, w;
    Edge() {
        s=inf; e=inf; w=inf;
    }
    Edge(int _s, int _e, int _w) {
        s=_s; e=_e; w=_w;
    }
}ed[2700];
int main() {
    int T, n, m, w, s, e, t;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &n, &m, &w);
        for(int i=0; i<=n; i++) {
            d[i] = inf;
        }
        for(int i=0; i<m; i++) {
            scanf("%d %d %d", &s, &e, &t);
            ed[i] = Edge(s,e,t);
        }
        int len = m+w;
        for(int i=m; i<len; i++) {
            scanf("%d %d %d", &s, &e, &t);
            ed[i] = Edge(s,e,-t);
        }

        d[1] = 0;
        bool isYes = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<len; j++) {
                if(d[ed[j].s]!=inf && (d[ed[j].e] > d[ed[j].s]+ed[j].w)) {
                    d[ed[j].e] = d[ed[j].s] + ed[j].w;
                    if(i==n-1) {
                        isYes = true;
                        break;
                    }
                }
                if(ed[j].w > 0) {
                    if(d[ed[j].e]!=inf && (d[ed[j].s] > d[ed[j].e]+ed[j].w)) {
                        d[ed[j].s] = d[ed[j].e] + ed[j].w;
                        if(i==n-1) {
                            isYes = true;
                            break;
                        }
                    }
                }
            }
        }
        if(isYes) puts("YES");
        else puts("NO");
    }
}
