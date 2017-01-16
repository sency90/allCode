#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define N 7
vector<vector<int> > v, g;
stack<int> s;
int ds[N], scc[N], scc_cnt[N], ds_cnt=0, sccno=0;
int dfs(int x) {
    s.push(x);
    int mnds = ds[x] = ++ds_cnt;
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(!ds[y]) mnds = min(mnds, dfs(y));
        else if(!scc[y]) mnds = min(mnds, ds[y]); //(x,y)가 back edge와 cross edge에 해당된다. 즉, 서브트리에서 ds값이 가장작은 vertex를 찾는 것이다. (현재 정점의 서브트리에서 가장 작은 ds값이 mnds에 담긴다)
        //(x,y)가 cross edge인데 y의 scc 번호가 결정되지 않은 경우 종만북에서 말한 특이한 예외사항이 발생한다.
        //(x,y)가 cross edge인데 y의 scc 번호가 결정된 경우, 그냥 무시하면 된다. 아무것도 아님.
    }

    //mnds에는 현재 정점을 제외한 현재 정점의 서브트리에서 발견할 수 있는 vertex의 가장 작은 ds값을 의미
    //그 값이 현재 정점의 ds값과 같다면, 지금까지 stack에 집어넣었던 모든 값들을 꺼내서 scc로 묶어준다.
    if(mnds == ds[x]) {
        sccno++;
        while(true) {
            int tmp = s.top(); s.pop();
            scc[tmp] = sccno;
            scc_cnt[sccno]++;
            if(x == tmp) break;
        }
    }
    return mnds;
}
int main() {
    int n=N;
    v.resize(n, vector<int>());
    v[0].push_back(1);
    v[0].push_back(4);
    v[0].push_back(5);
    v[0].push_back(6);
    v[5].push_back(3);
    v[5].push_back(6);
    v[6].push_back(3);
    v[4].push_back(2);
    v[1].push_back(2);
    v[2].push_back(0);

    for(int i=0; i<n; i++) {
        if(!ds[i]) dfs(i);
    }

    //SCC DAG 만들기
    g.resize(sccno+1, vector<int>());
    for(int i=0; i<n; i++) {
        for(int to: v[i]) {
            g[scc[i]].push_back(scc[to]);
        }
    }
    for(int i=1; i<=sccno; i++) { //[1,sccno] 구간 조심할 것!
        g[i].erase(unique(g[i].begin(),g[i].end()), g[i].end());
    }



    for(int i=0; i<n; i++) {
        cout << i << ": "<< scc[i] << "\n";
    }
    return 0;
}
