#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
char d[11];
int next(int x, int y, int mod) {
    int ret = x*10+y;
    if(ret >= mod) return mod + ret%mod;
    else return ret%mod;
}
vector<int> v, pa, choose;
void bfs(int n, int m) {
    queue<int> q;
    pa.clear(); choose.clear();
    pa.resize(2*n, -1); choose.resize(2*n);

    pa[0]=0;
    q.push(0);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i=0; i<v.size(); i++) {
            int y = next(x,v[i],n);
            if(pa[y]==-1) {
                pa[y] = x;
                choose[y] = v[i];
                if(y == m+n) return;
                q.push(y);
            }
        }
    }
}
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n, m;
        scanf("%s%d%d", d,&n,&m);
        int lim = strlen(d);
        v.clear(); v.resize(lim);
        for(int i=0; i<lim; i++) v[i] = d[i]-'0';
        sort(v.begin(), v.end());

        bfs(n,m);
        int x=n+m;
        if(pa[x] == -1) puts("IMPOSSIBLE");
        else {
            stack<int> s;
            for(x=n+m; x!=pa[x]; x=pa[x]) s.push(choose[x]);
            while(!s.empty()) {
                printf("%d", s.top()); s.pop();
            }
            puts("");
        }
    }
    return 0;
}
