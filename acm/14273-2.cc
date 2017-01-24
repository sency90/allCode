#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct MaximumFlow {
    struct Edge {
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap) {
        add_edge(source, v, cap);
    }
    void add_edge_to_sink(int u, int cap) {
        add_edge(u, sink, cap);
    }
    int bfs() {
        vector<bool> check(n, false);
        vector<pair<int,int>> from(n, make_pair(-1,-1));
        queue<int> q;
        q.push(source);
        check[source] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i=0; i<graph[x].size(); i++) {
                if (graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {
                    q.push(graph[x][i]->to);
                    check[graph[x][i]->to] = true;
                    from[graph[x][i]->to] = make_pair(x,i);
                }
            }
        }
        if (!check[sink]) {
            return 0;
        }
        int x = sink;
        int c = graph[from[x].first][from[x].second]->capacity;
        while (from[x].first != -1) {
            if (c > graph[from[x].first][from[x].second]->capacity) {
                c = graph[from[x].first][from[x].second]->capacity;
            }
            x = from[x].first;
        }
        x = sink;
        while (from[x].first != -1) {
            Edge *e = graph[from[x].first][from[x].second];
            e->capacity -= c;
            e->rev->capacity += c;
            x = from[x].first;
        }
        return c;
    }
    int flow() {
        int ans = 0;
        while (true) {
            int f = bfs();
            if (f == 0) break;
            ans += f;
        }
        return ans;
    }
};
void compress(vector<int> &x, int &n) {
    set<int> a;
    for (int i=0; i<x.size(); i++) {
        for (int xx = max(1,x[i]-3); xx <= min(x[i]+3, n); xx++) {
            a.insert(xx);
        }
    }
    n = a.size();
    for (int i=0; i<x.size(); i++) {
        int p = 0;
        set<int>::iterator q = a.begin();
        while ((q!=a.end()) && (*q < x[i])) {
            q++;
            p++;
        }
        x[i] = p;
    }
}
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int inf = 1000000;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(7), y(7);
    for (int i=0; i<7; i++) {
        cin >> x[i] >> y[i];
    }
    compress(x,n);
    compress(y,m);
    auto in_node = [&](int i, int j) {
        return 2*(i*m+j);
    };
    auto out_node = [&](int i, int j) {
        return in_node(i, j)+1;
    };
    MaximumFlow mf(2*n*m+2, 2*n*m, 2*n*m+1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (x[0] != i || y[0] != j) {
                mf.add_edge(in_node(i,j),out_node(i,j),1);
            }
            for (int k=1; k<=3; k++) {
                if (x[k] == i && y[k] == j) {
                    mf.add_edge_from_source(in_node(i,j),1);
                }
                if (x[k+3] == i && y[k+3] == j) {
                    mf.add_edge_to_sink(out_node(i,j),1);
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<4; k++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if (0 <= x && x < n && 0 <= y && y < m) {
                    mf.add_edge(out_node(i,j),in_node(x,y),inf);
                }
            }
        }
    }
    if (mf.flow() == 3) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
