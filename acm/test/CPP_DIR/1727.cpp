#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int d[1001][1001];
int abs(int x) { return x<0?-x:x; }
int f(int bs, int gs, const vector<int> &b, const vector<int> &g) {
    if(bs == b.size()) return 0;

    int &ret = d[bs][gs];
    if(ret < inf) return ret;
    if(b.size()-bs > g.size()-gs) ret = f(bs+1,gs,b,g);
    return ret = min(ret, abs(b[bs]-g[gs])+f(bs+1,gs+1,b,g));
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> b(n), g(m);
    memset(d,0x3f,sizeof(d));
    for(int i=0; i<n; i++) { scanf("%d", &b[i]); }
    for(int i=0; i<m; i++) { scanf("%d", &g[i]); }
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    if(n > m) printf("%d", f(0,0,b,g));
    else printf("%d", f(0,0,g,b));
    return 0;
}
