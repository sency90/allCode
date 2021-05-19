//ntopia's source code

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int n, m, c;
struct Edge {
    int w, to;
    bool operator<(const Edge& a) const {
        return w > a.w;
    }
};
vector<Edge> graph[25001];
vector<pair<int, int>> carInit;
 
int dist[25001];
vector<int> via[25001];
 
struct MaxFlow {
    typedef int flow_t;
    struct Edge {
        int next;
        int inv; /* inverse edge index */
        flow_t cap;
        flow_t res; /* residual */
    };
 
    int n;
    vector<vector<Edge>> graph;
    vector<int> visit;
    int counter;
 
    void Init(int _n){
        n = _n;
        counter = 0;
        graph.resize(n);
        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }
        visit.resize(n);
        memset(&visit[0], 0, sizeof(visit[0]) * visit.size());
    }
    void AddEdge(int s, int e, flow_t cap, flow_t caprev = 0) {
        Edge forward = { e, graph[e].size(), cap, cap };
        Edge reverse = { s, graph[s].size(), caprev, caprev };
        graph[s].push_back(forward);
        graph[e].push_back(reverse);
    }
    void ClearFlow() {
        for (int i = 0; i < n; ++i) {
            for (auto& edge : graph[i]) {
                edge.res = edge.cap;
            }
        }
    }
 
    flow_t dfs(int u, int ed, int curflow) {
        visit[u] = counter;
        if (u == ed) {
            return curflow;
        }
        for (int i = 0; i < graph[u].size(); ++i) {
            auto& edge = graph[u][i];
            if (edge.res <= 0 || visit[edge.next] == counter) {
                continue;
            }
            flow_t ret = dfs(edge.next, ed, min(curflow, edge.res));
            if (ret > 0) {
                edge.res -= ret;
                graph[edge.next][edge.inv].res += ret;
                return ret;
            }
        }
        return 0;
    }
 
    flow_t Solve(int source, int sink) {
        flow_t ans = 0;
        while (true) {
            ++counter;
            flow_t flow = dfs(source, sink, 2147483647);
            if (flow == 0) {
                break;
            }
            ans += flow;
        }
        return ans;
    }
};
 
void proc() {
    scanf("%d %d %d", &n, &m, &c);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(Edge{ c, b });
        graph[b].push_back(Edge{ c, a });
    }
 
    for (int i = 1; i <= n; ++i) {
        dist[i] = 100000000;
    }
    priority_queue<Edge> pq;
    dist[1] = 0;
    pq.push(Edge{ 0, 1 });
    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();
        if (cur.w > dist[cur.to]) {
            continue;
        }
        for (const auto& edge : graph[cur.to]) {
            if (dist[edge.to] > dist[cur.to] + edge.w) {
                dist[edge.to] = dist[cur.to] + edge.w;
                pq.push(Edge{ dist[edge.to], edge.to });
                via[edge.to].clear();
                via[edge.to].push_back(cur.to);
            }
            else if (dist[edge.to] == dist[cur.to] + edge.w) {
                via[edge.to].push_back(cur.to);
            }
        }
    }
 
    for (int i = 0; i < c; ++i) {
        int v;
        scanf("%d", &v);
        carInit.push_back({ dist[v], v });
    }
    sort(carInit.begin(), carInit.end());
 
    MaxFlow mf;
    mf.Init(n + c + 2);
    for (int k = 1; k <= n; ++k) {
        for (int v : via[k]) {
            mf.AddEdge(k, v, 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < carInit.size(); ) {
        mf.ClearFlow();
        int ss = n + 1 + i;
 
        int j = i;
        while (j < carInit.size() && carInit[i].first == carInit[j].first) {
            int k = j, cnt = 0;
            while (k < carInit.size() && carInit[j].second == carInit[k].second) {
                ++k;
                ++cnt;
            }
            mf.AddEdge(ss, carInit[j].second, cnt);
            j = k;
        }
        ans += mf.Solve(ss, 1);
 
        i = j;
    }
    printf("%d", ans);
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    proc();
    return 0;
}