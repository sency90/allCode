#include <stdio.h>
#include <cstring>
using namespace std;
int inf = 100000000;
struct Edge{
    int s, e, w;
}ed[6001];
int d[501];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<=n; i++) {
        d[i] = inf;
    }
    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &ed[i].s, &ed[i].e, &ed[i].w);
    }
    d[1] = 0;
    bool wrongAns = false;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<m; j++) {
            if(d[ed[j].e] > d[ed[j].s]+ ed[j].w && d[ed[j].s]!=inf) {
                d[ed[j].e] = d[ed[j].s]+ ed[j].w;
                if(i==n) {
                    wrongAns = true;
                    break;
                }
            }
        }
    }
    if(wrongAns) {
        puts("-1");
        return 0;
    }
    for(int i=2; i<=n; i++) {
        if(d[i]==inf) puts("-1");
        else printf("%d\n", d[i]);
    }
    return 0;
}
