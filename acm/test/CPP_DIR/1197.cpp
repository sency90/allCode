#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <string.h>
#include <functional>
using namespace std;

struct Edge {
    int target;
    int cost;

    bool operator>(const Edge& rhs) const {
        return cost > rhs.cost;
    }
};

int main() {
    Edge minE, inputE;
    vector<Edge> v[100001];
    priority_queue< Edge, vector<Edge>, greater<Edge> > minHeap;
    bool marked[10001];

    memset(marked, false, sizeof(marked));

    int n, e;
    scanf("%d %d", &n, &e);

    //create a graph data structure
    int s=0, t, c;
    for(int i=0; i<e; i++) {
        scanf("%d %d %d", &s, &t, &c);
        inputE.target = t;
        inputE.cost = c;
        v[s].push_back(inputE);
        inputE.target = s;
        v[t].push_back(inputE);
    }

    //calculate the minimum cost of the M.S.T
    //by using the 'Prim Algorithm' and the 'Min Heap' structure
    marked[s] = true;
    long long totalCost = 0;
    for(int i=s, cnt=0; cnt<n || !minHeap.empty(); cnt++) {
        for(int j=0; j<v[i].size(); j++) {
            if(marked[v[i][j].target]) continue;
            minHeap.push(v[i][j]);
        }

        if(minHeap.empty()) continue;
        minE = minHeap.top();
        minHeap.pop();

        if(marked[minE.target]) continue;
        marked[minE.target] = true;
        totalCost += minE.cost;
        i = minE.target;
    }

    printf("%lld\n", totalCost);
    return 0;
}
