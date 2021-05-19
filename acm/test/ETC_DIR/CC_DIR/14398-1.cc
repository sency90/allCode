#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
//using std::vector;
typedef long long ll;
int gcd(ll b, ll s) {
    return (s==0)?b:gcd(s,b%s);
}
struct BipartiteMatching {
    vector<int> L;
    vector<int> R;
    vector<vector<int>> G;
    vector<int> dist;
    BipartiteMatching(int n, int m) {
        L.resize(n, -1);
        R.resize(m, -1);
        G.resize(n);
        dist.resize(n);
    }
    void add_edge(int from, int to) {
        G[from].push_back(to);
    }
    bool bfs() {
        std::queue<int> que;
        for (int i = 0; i < L.size(); i++) {
            if (L[i] == -1) {
                dist[i] = 0;
                que.push(i);
            }
            else {
                dist[i] = -1;
            }
        }
        bool flag = false;
        while (!que.empty()) {
            int idx = que.front();
            que.pop();
            for (int to : G[idx]) {
                if (R[to] == -1)flag = true;
                else if (dist[R[to]] == -1) {
                    dist[R[to]] = dist[idx] + 1;
                    que.push(R[to]);
                }
            }
        }
        return flag;
    }
    bool dfs(int idx) {
        for (int to : G[idx]) {
            if (R[to] == -1 || (dist[idx]<dist[R[to]] && dfs(R[to]))) {
                R[to] = idx;
                L[idx] = to;
                return true;
            }
        }
        dist[idx] = -1;
        return false;
    }
    int matching() {
        int ret = 0;
        while (bfs()) {
            for (int i = 0; i < L.size(); i++) {
                if (L[i] == -1 && dfs(i)) {
                    ret++;
                }
            }
        }
        return ret;
    }
};
ll in[201];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &in[i]);
    }
    auto valid = [&](ll x, ll y) {
        if(y<x) swap(x,y);
        ll c = x*x+y*y;
        ll res = sqrt(c);
        if(c==res*res) return true;
        if(c==(res-1)*(res-1)) return true;
        if(c==(res+1)*(res+1)) return true;
        return false;
    };

    BipartiteMatching b(n,n);
    sort(in, in+n);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(in[i]!=in[j]) {
                if(valid(in[i],in[j]) && gcd(in[i],in[j])==1) {
                    b.add_edge(i,j);
                    //v[i].push_back(j);
                }
            }
        }
    }
    printf("%d\n", b.matching());
    return 0;
}
