#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> list;
vector<int> v;
vector<vector<int>> g;
bool dfs(int x, int k) {
    if(x==-1) {
        return true;
    }
    for(int i=g[x].size()-1; i>=0; i--) {
        int yidx = g[x][i];
        if(yidx < k) {
            if(dfs(x-1, yidx)) return true|printf("%d ", list[yidx]);
        }
    }
    return false;
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        list.push_back(x);
        auto it = lower_bound(v.begin(), v.end(), x);
        if(it == v.end()) {
            v.push_back(x);
            g.push_back(vector<int>());
            g.back().emplace_back(i);
        }
        else {
            *it = x;
            g[it - v.begin()].emplace_back(i);
        }
    }

    printf("%lu\n", v.size());
    dfs(g.size()-1, n);
    puts("");
    return 0;
}
