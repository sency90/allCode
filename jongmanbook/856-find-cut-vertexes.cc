//JMBook 856 page graph -> find cut vertexes
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
vector<vector<int> > v;
vector<bool> isCutVertex;
vector<int> discovered;
int counter=0;
int dfs2(int x) {
    int children=0, mn=discovered[x]=++counter;
    for(int y: v[x]) {
        if(discovered[y]) mn = min(mn, discovered[y]);
        else {
            children++;
            int subtree = dfs2(y);
            if(discovered[x]!=1 && subtree >= discovered[x]) isCutVertex[x] = true;
            mn = min(mn, subtree);
        }
    }
    if(discovered[x]==1 && children>=2) { //if x is the root
        isCutVertex[x] = true;
    }
    return mn;
}
void e(int x, int y) { v[x].push_back(y); v[y].push_back(x); }
int main() {
    int n=7;
    v.resize(n, vector<int>());
    discovered.resize(n, 0);
    isCutVertex.resize(n, false);

    //undirected graph
    /*
       e(0,1);
       e(1,2);
       e(2,0);
       */
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
