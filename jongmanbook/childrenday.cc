#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int next(int x, int z, int mod) {
    int tmp = 10*x+z;
    if(tmp >= mod) return mod + tmp%mod;
    else return tmp%mod;
}

vector<int> v, p;
int choose[20001];
void bfs(int n, int m) {
    queue<int> q;
    p[0]=0;
    q.push(0);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(x == n+m) return;
        for(int i=0; i<v.size(); i++) {
            int y = next(x, v[i], n);
            if(p[y]==-1) {
                p[y] = x;
                choose[y] = v[i];
                if(y == n+m) return;
                q.push(y);
            }
        }
    }
}

char d[11];
int main() {
    int tc,m,n;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%s%d%d",d,&n,&m);
        v.clear(); p.clear();
        p.resize(2*n, -1);
        int lim = strlen(d);
        for(int i=0; i<lim; i++) {
            v.push_back(d[i]-'0');
        }
        sort(v.begin(), v.end());

        memset(choose, 0, sizeof(choose));
        bfs(n,m);
        int x = n+m;
        if(p[x] == -1) puts("IMPOSSIBLE");
        else {
            stack<int> s;
            while(x!=p[x]) {
                s.push(choose[x]);
                x=p[x];
            }

            while(!s.empty()) {
                printf("%d", s.top()); s.pop();
            }
            puts("");
        }
    }
    return 0;
}
