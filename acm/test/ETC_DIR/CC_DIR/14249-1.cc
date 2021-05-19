#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> v[100001], g[100001];
stack<int> s;
int cnt=1, sccno=0, n;
int ds[100001], scc[100001], scnt[100001];
bool chk(int x) { return (x>=0)&&(x<n); }
int dfs(int x) {
    s.push(x);
    int mnds = ds[x] = cnt++;
    for(int y: v[x]) {
        if(!ds[y]) mnds = min(mnds, dfs(y));
        else if(!scc[y]) mnds = min(mnds, ds[y]);
    }

    if(mnds == ds[x]) {
        sccno++;
        while(true) {
            int tmp = s.top(); s.pop();
            scc[tmp]=sccno;
            scnt[sccno]++;
            if(tmp == x) break;
        }
    }
    return mnds;
}
vector<int> d;
int f(int x) {
    int &ret = d[x];
    if(ret>=0) return ret;
    else ret=0;
    for(int y: g[x]) ret = max(ret,f(y));
    return ret+=scnt[x];
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        if(chk(i-x)) v[i].push_back(i-x);
        if(chk(i+x)) v[i].push_back(i+x);
    }
    int k; scanf("%d", &k);
    dfs(k-1);

    for(int i=0; i<n; i++) {
        for(int y: v[i]) {
            g[scc[i]].push_back(scc[y]);
        }
    }
    for(int i=1; i<=sccno; i++) g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    d.resize(sccno+1,-1);
    printf("%d\n", f(scc[k-1]));
    return 0;
}
