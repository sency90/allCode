#include <vector>
#include <cstring>
using namespace std;
vector<int> v[1001];
bool chk[1001];
struct Edge{
    int s,e,prv;
};
Edge e[10001];
int to[1001];
void dfs(int x) {
    printf("%d ", x);
    chk[x] = true;
    for(int i=to[x]; i!=-1; i=e[i].prv) {
        int y = e[i].e;
        if(chk[y]) continue;
        dfs(y);
    }
}
int main() {
    int n,m; scanf("%d%d", &n, &m);
    int M = m*2;
    for(int i=0; i<n; i++) to[i]=-1;
    for(int i=0; i<M; i+=2) {
        int x,y; scanf("%d%d", &x,&y);
        e[i].s=x; e[i].e=y;
        e[i+1].s=y; e[i+1].e=x;
        e[i].prv = to[x];
        e[i+1].prv = to[y];
        to[x]=i;
        to[y]=i+1;
    }
    dfs(0);
    puts("");
    return 0;
}
