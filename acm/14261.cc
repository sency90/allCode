#include <cstdio>
using namespace std;
#define x2 (x<<1)
#define y2 (y<<1)
int main() {
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        v[x2].push_back(x2+1);
        r[x2][x2+1]=x;
    }
    for(int i=0; i<m; i++) {
        int x,y; scanf("%d%d",&x,&y);
        v[x2+1].push_back(y2);
        v[y2+1].push_back(x2);
    }

    return 0;
}
