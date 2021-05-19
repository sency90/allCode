#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> fen;
int n,m;
int lastPos[200001];
void update(int at, int by) {
    for(;at<=n+m; at+=at&-at) fen[at] += by;
}
int query(int at) {
    int ret = 0;
    if(at==0) return 0;
    for(;at;at-=at&-at) ret += fen[at];
    return ret;
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d",&n,&m);
        fen.clear(); fen.resize(n+m+1, 0);
        for(int i=1; i<=n; i++) {
            update(i+m,1);
            lastPos[i] = i+m;
        }
        for(int i=0; i<m; i++) {
            int x; scanf("%d", &x);
            printf("%d ", query(lastPos[x]-1));
            update(lastPos[x], -1);
            update(m-i, 1);
            lastPos[x] = m-i;
        }
        puts("");
    }
    return 0;
}
