#include <cstdio>
using namespace std;
int p[1001];
void init(int n) {
    for(int i=1; i<=n; i++) p[i]=i;
}
int find(int x) {
    if(x == p[x]) return x;
    else return p[x] = find(p[x]);
}
bool uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    else p[y] = x;
    return true;
}
int main() {
    int n,m; scanf("%d%d",&n,&m);
    init(n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int x; scanf("%d", &x);
            if(x) uni(i,j);
        }
    }

    int x; scanf("%d", &x);
    int r = find(x);
    bool good = true;
    for(int i=1; i<m; i++) {
        scanf("%d", &x);
        if(find(x)!=r) good = false;
    }

    if(good) puts("YES");
    else puts("NO");
    return 0;
}
