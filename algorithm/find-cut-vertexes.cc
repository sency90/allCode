//JMBook 856 page graph -> find cut vertexes
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int> > v;
vector<bool> isCutVertex;
vector<int> discovered;
int counter=0;
int dfs2(int x) {
    discovered[x] = ++counter;
    int children=0, mn=discovered[x];
    for(int i=0; i<v[x].size(); i++) {
        children++;
        int y = v[x][i];
        if(discovered[y]) {
            mn = min(mn, discovered[y]);
            continue;
        }
        int subtree = dfs2(y);
        if(discovered[x]!=1 && subtree >= discovered[x]) isCutVertex[x] = true;
        mn = min(mn, subtree);
    }
    if(discovered[x] == 1) { //if x is the root
        isCutVertex[x] = (children >= 2);
        return discovered[x];
    } else return mn;
}
int main() {
    int n=7;
    v.resize(n, vector<int>());
    discovered.resize(n, 0);
    isCutVertex.resize(n, false);

    //undirected graph
    v[0].push_back(1); v[1].push_back(0);
    v[0].push_back(4); v[4].push_back(0);
    v[0].push_back(5); v[5].push_back(0);
    v[0].push_back(6); v[6].push_back(0);
    v[5].push_back(3); v[3].push_back(5);
    v[5].push_back(6); v[6].push_back(5);
    v[6].push_back(3); v[3].push_back(6);
    v[4].push_back(2); v[2].push_back(4);
    v[1].push_back(2); v[2].push_back(1);
    v[2].push_back(0); v[0].push_back(2);

    //check cut vertex
    dfs2(0);

    for(int i=0; i<n; i++) {
        if(isCutVertex[i]) cout << i << " ";
    }
    puts("");
    return 0;
}
