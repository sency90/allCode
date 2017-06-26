//JMBook 856 page graph -> find cut vertexes
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int> > v;
vector<int> discov,cv;
int cnt=0;
int dfs(int x) {
    int ret=discov[x]=++cnt, tEdge=0;
    for(int y: v[x]) {
        if(discov[y]) ret = min(ret,discov[y]);
        else {
            tEdge++;
            int subtree=dfs(y);
            //>= 이 부등호가 정말 중요하다. =빼먹으면 안됨. (bridge와 cut-vertex의 차이)
            if(discov[x]!=1 && subtree >= discov[x]) cv.push_back(x);
            ret = min(ret,subtree);
        }
    }
    //v[x].size()로 tEdge를 대체할 수 없음. treeEdge의 개수는 v[x].size()가 아니기 때문.
    if(discov[x]==1 && tEdge>=2) cv.push_back(x);
    return ret;
}
void e(int x, int y) {
    v[x].push_back(y); v[y].push_back(x);
}
int main() {
    int n=7;
    v.resize(n, vector<int>());
    discov.resize(n, 0);

    //undirected graph
    /*
       e(0,1);
       e(1,2);
       e(2,0);
       */
    e(0,1);
    e(0,4);
    e(0,5);
    e(0,6);
    e(5,3);
    e(5,6);
    e(6,3);
    e(4,2);
    e(1,2);
    e(2,0);


    //check cut vertex
    dfs(0);

    printf("Cut Vertexes: ");
    for(int p: cv) {
        printf("%d ", p);
    } puts("");

    return 0;
}
