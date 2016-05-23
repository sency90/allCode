#include <stdio.h>
#include <cstring>
#include <limits.h>
#include <string>
#include <iostream>
using namespace std;
int d[501];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
struct Edge{
    int s, e, w;
    Edge() {
        s=0; e=0; w=0;
    }
    Edge(int _s, int _e, int _w) {
        s=_s; e=_e; w=_w;
    }
}ed[5402];
int inf = INT_MAX/2-1;
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
            ed[i+m] = Edge(e,s,t);
        }
        int len =2*m+w;
        for(int i=2*m; i<len; i++) {
            scanf("%d %d %d", &s, &e, &t);
            ed[i] = Edge(s,e,-t);
            ed[i+w] = Edge(e,s,-t);
        }

        d[1] = 0;
        len += w;
        string ans = "NO";
        for(int i=0; i<n; i++) {
            for(int j=0; j<len; j++) {
                if(d[ed[j].s]!=inf && d[ed[j].e] > d[ed[j].s]+ed[j].w) {
                    d[ed[j].e] = d[ed[j].s] + ed[j].w;
                    if(i==n-1) {
                        ans="YES";
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
