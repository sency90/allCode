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
    priority_queue< Edge, vector<Edge>, greater<Edge> > minHeap;
    vector<Edge> v[10001];
    bool marked[10001];
    int node[10001];
    memset(marked, false, sizeof(marked));
    for(int i=0; i<10001; i++) node[i] = INT_MAX;

    int n, e;
    scanf("%d %d", &n, &e);

    //create a graph data structure
    int s, t, c;
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
    marked[1] = true;
    int totalCost = 0;
    for(int i=1, cnt=0; cnt<n; cnt++) {
        for(int j=0; j<v[i].size(); j++) {
            if(marked[v[i][j].target]) continue;
            minHeap.push(v[i][j]);
        }

        minE = minHeap.top();
        minHeap.pop();
        if(marked[minE.target]) continue;
        printf("%d-->%d\t%d\n", i, minE.target, minE.cost);
        marked[minE.target] = true;
        totalCost += minE.cost;
        i = minE.target;
    }

    printf("%d\n", totalCost);
    while(!minHeap.empty()) minHeap.pop();
    return 0;
}
