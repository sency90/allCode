#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[100001], b[100001];
vector<int> v[100001], r;
void dfs(int x, int y) {
    for(int i=0; i<v[x].size(); i++) {
        if(v[x][i]==y) continue;
        dfs(v[x][i], x);
        a[x] += b[v[x][i]];
        b[x] += max(a[v[x][i]], b[v[x][i]]);
    }
}
void print(int x, int y, int z) {
    if(z) r.push_back(x);
    for(int i=0; i<v[x].size(); i++) {
        if(v[x][i]==y) continue;
        print(v[x][i], x, !z && a[v[x][i]]>b[v[x][i]]);
    }
}
int main() {
    int n, x, y;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", a+i);
    }
    for(int i=1; i<n; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    printf("%d\n", max(a[1],b[1]));
    print(1,0,a[1]>b[1]);
    sort(r.begin(), r.end());
    for(auto h : r) printf("%d ", h);
    return 0;
}
