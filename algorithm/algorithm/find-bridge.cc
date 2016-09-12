//JMBook 858 page graph -> find bridge
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int> > v;
vector<vector<bool> > isCutVertex;
vector<int> discovered;
int counter=0;
//v[parent][x] 오직 하나만 존재할 때 가능한 코드.
int dfs2(int x, int parent) {
    discovered[x] = ++counter;
    int mn=discovered[x];
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(y == parent) continue;
        if(discovered[y]) {
            mn = min(mn, discovered[y]);
            continue;
        }
        int subtree = dfs2(y, x);
        if(discovered[x]!=1 && subtree >= discovered[x]) isCutVertex[x][y] = true;
        mn = min(mn, subtree);
    }
    return mn;
}
int main() {
    int n=7;
    v.resize(n, vector<int>());
    discovered.resize(n, 0);
    isCutVertex.resize(n, vector<bool>(n, false));
    v[0].push_back(1); v[1].push_back(0);
    //v[0].push_back(4); v[4].push_back(0);
    v[0].push_back(5); v[5].push_back(0);
    v[0].push_back(6); v[6].push_back(0);
    v[5].push_back(3); v[3].push_back(5);
    v[5].push_back(6); v[6].push_back(5);
    //v[6].push_back(3); v[3].push_back(6);
    v[4].push_back(2); v[2].push_back(4);
    v[1].push_back(2); v[2].push_back(1);
    v[2].push_back(0); v[0].push_back(2);
    dfs2(0, -1);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(isCutVertex[i][j]) printf("(%d, %d) ", i, j); 
        }
    }
    puts("");
    return 0;
}
