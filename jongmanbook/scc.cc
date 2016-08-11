#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int> > v;
vector<vector<int> > scc;
int counter=0, sccCnt=0;
bool in = false;
int dfs(int x, int parent) {
    ds[x] == ++counter;
    int mn = ds[x];
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(y==parent) continue;
        else if(ds[y]) {
            if(ds[y] < ds[x]) { // (x,y)가 cross edge인 경우
                if(scc[y]!=-1) { //scc에 y정점이 속한다면

                }
            }
            mn = min(ds[x], ds[y]);
            continue;
        } else {
            int subtree = dfs(y, x);
            if(subtree >= ds[x]) {
                if(!in) {
                    in = true;
                    sccCnt++;
                    root[sccCnt] = x;
                }
            } else { //back edge가 있는 경우
                in = false;
                scc[x]=sccCnt;
            }
        }
    }
}
int main() {
    v[0].push_back(3);
    v[3].push_back(0);
    v[0].push_back(5);
    v[5].push_back(4);
    v[4].push_back(5);
    v[4].push_back(1);
    v[1].push_back(3);
    v[3].push_back(2);
    v[2].push_back(1);
    dfs(0, -1);
    return 0;
}
