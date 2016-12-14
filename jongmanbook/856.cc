//JMBook 856 page graph -> find cut vertexes
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<vector<int> > v;
vector<int> discov,cv;
int cnt=0;
int dfs(int x) {
    discov[x]=++cnt;
    int ret = inf;
    for(int y: v[x]) {
        if(discov[y]) ret = min(ret,discov[y]);
        else {
            int subtree=dfs(y);
            //>= 이 부등호가 정말 중요하다. =빼먹으면 안됨. (bridge와 cut-vertex의 차이)
            if(discov[x]!=1 && subtree >= discov[x]) cv.push_back(x);
            ret = min(ret,subtree);
        }
    }
    if(discov[x]==1) if(v[x].size()>=2) cv.push_back(x);

    return min(ret,discov[x]);
}
void e(int x, int y) {
    v[x].push_back(y); v[y].push_back(x);
}
int main() {
    int n=7;
    v.resize(n, vector<int>());
    discov.resize(n, 0);

    //undirected graph
    e(0,1);
    e(1,2);

    //check cut vertex
    dfs(0);

    puts("Cut Vertexes:");
    for(int p: cv) {
        printf("%d\n", p);
    }

    return 0;
}

