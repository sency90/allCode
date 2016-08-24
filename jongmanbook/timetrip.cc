#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int inf = 1000000;
struct Edge{
    int s,e,w;
    Edge(){} Edge(int s, int e, int w):s(s),e(e),w(w) {}
};
vector<Edge> v;
int mn[101], mx[101];
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int G,W,s,e,w;
        v.clear();
        scanf("%d%d",&G,&W);
        for(int i=0; i<W; i++) {
            scanf("%d%d%d",&s,&e,&w);
            v.push_back(Edge(s,e,w));
        }

        memset(mn, 0x3f, sizeof(mn));
        memset(mx, 0xc0, sizeof(mx));
        mn[0]=mx[0]=0;
        bool mninf=false, mxinf=false;
        for(int i=1; i<=G; i++) {
            for(int j=0; j<v.size(); j++) {
                if(mn[v[j].e] > mn[v[j].s]+v[j].w) {
                    mn[v[j].e] = mn[v[j].s]+v[j].w;
                    if(i==G) mninf = true;
                }
                if(mx[v[j].e] < mx[v[j].s]+v[j].w) {
                    mx[v[j].e] = mx[v[j].s]+v[j].w;
                    if(i==G) mxinf = true;
                }
            }
        }

        if(mn[1]>inf || mx[1]<-inf) puts("UNREACHABLE");
        else {
            if(mninf) printf("INFINITY ");
            else printf("%d ", mn[1]);
            if(mxinf) printf("INFINITY\n");
            else printf("%d\n", mx[1]);
        }
    }
    return 0;
}
