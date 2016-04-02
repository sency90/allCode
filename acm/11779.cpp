#include <stdio.h>
#include <vector>
#include <cstring>
#define INF 1000000001
using namespace std;
struct Edge{
    int e, w;
};
vector<Edge> v[1001];
bool chk[1001], isFirst = true;
int d[1001], vtx[1001], cnt = 0;
void search(int x) {
    cnt++;
    if(vtx[x]!=-1) search(vtx[x]);
    if(isFirst) {
        printf("%d\n", cnt);
        isFirst = false;
    }
    printf("%d ", x);
}
int main() {
    int n, m, s, e, x, mn;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) d[i] = INF;
    Edge in;
    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &s, &in.e, &in.w);
        v[s].push_back(in);
    }
    scanf("%d %d", &s, &e);
    memset(chk, false, sizeof(chk));
    d[s] = 0; vtx[s] = -1;
    for(int i=1; i<=n; i++) {
        mn = INF+1;
        for(int j=1; j<=n; j++) {
            if(!chk[j] && mn > d[j]) {
                mn = d[j];
                x = j;
            }
        }
        chk[x] = true;
        for(int j=0; j<v[x].size(); j++) {
            if(d[v[x][j].e] > d[x] + v[x][j].w) {
                d[v[x][j].e] = d[x] + v[x][j].w;
                vtx[v[x][j].e] = x;
            }
        }
    }
    printf("%d\n", d[e]);
    search(e);
}
