#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[201][201],v;
const int inf = 0x3f3f3f3f;
bool update(int s, int e, int w) {
    if(a[s][e]<=w) return false;

    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            a[i][j] = min({a[i][j], a[i][s]+w+a[e][j], a[i][e]+w+a[s][j]});
        }
    }
    return true;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        memset(a, 0x3f, sizeof(a));
        int m,n,s,e,w;
        scanf("%d%d%d",&v,&m,&n);
        for(int i=0; i<v; i++) a[i][i]=0;
        for(int i=0; i<m; i++) {
            scanf("%d%d%d",&s,&e,&w);
            a[s][e]=a[e][s]=w;
        }

        for(int k=0; k<v; k++) {
            for(int i=0; i<v; i++) {
                if(a[i][k] == inf) continue;
                for(int j=0; j<v; j++) {
                    if(a[i][j] > a[i][k]+a[k][j]) {
                        a[i][j] = a[i][k]+a[k][j];
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++) {
            scanf("%d%d%d",&s,&e,&w);
            if(!update(s,e,w)) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
