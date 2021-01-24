#include <cstdio>
#include <vector>
#define L 0
#define R 1
using namespace std;
vector<int> v;
int g[1000001][2];
const int inf = 1000000;
void dfs(int x) {
    if(g[x][L]<inf) dfs(g[x][L]);
    if(g[x][R]<inf) dfs(g[x][R]);
    if(x!=inf) printf("%d\n", x);
}

int mkTree(int l, int r) {
    if(l>r) return inf;
    int lo=l+1, hi=r;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(v[l]>v[mid]) lo=mid+1;
        else hi=mid-1;
    }
    g[v[l]][L] = mkTree(l+1,lo-1);
    g[v[l]][R] = mkTree(lo,r);
    return v[l];
}
int main() {
    int x;
    v.push_back(inf);
    while(~scanf("%d", &x)) {
        v.push_back(x);
    }
    mkTree(0,v.size()-1);
    dfs(g[inf][L]);
    return 0;
}
