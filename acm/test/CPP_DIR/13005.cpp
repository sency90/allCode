#include <stdio.h>
#include <vector>
using namespace std;
struct Edge{
    int e,w;
    Edge() {}
    Edge(int ee, int ww) {e=ee;w=ww;}
};
vector<int> a;
vector<Edge> v[100001];
bool chk[100001];
int cnt=0;
void dfs(int x, int cs, bool shouldCut) {
    chk[x] = true;
    if(a[x]<cs || shouldCut) {
        cnt++;
        shouldCut = true;
    }

    for(int i=0; i<v[x].size(); i++) {
        int e=v[x][i].e, w=v[x][i].w;
        if(chk[e]) continue;
        if(cs+w<0) dfs(e,0,shouldCut);
        else dfs(e,cs+w,shouldCut);
    }
}

int main() {
    int n,e,w;
    scanf("%d", &n);
    a.resize(n+1);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=2; i<=n; i++) {
        scanf("%d%d",&e,&w);
        v[i].push_back(Edge(e,w));
        v[e].push_back(Edge(i,w));
    }

    dfs(1,0,false);
    printf("%d", cnt);
    return 0;
}
