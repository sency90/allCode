#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define N 7
vector<vector<int> > v;
stack<int> s;
int ds[N], scc[N], ds_cnt=0, scc_cnt=1;
int dfs(int x) {
    s.push(x);
    int mnds = ds[x] = ++ds_cnt;
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(!ds[y]) mnds = min(mnds, dfs(y));
        else if(!scc[y]) mnds = min(mnds, ds[y]); //(x,y)가 cross edge에 해당하는데 y가 아직 scc에 해당하지 않는 다는건 그 y에서 x와 y의 루트인 z를 거쳐서 다시 x로 돌아올 수 있는 경로가 있을 수도 있다는 뜻이므로(반드시 그런것은 아님) 그 경우를 확인해 주는 부분이다.
    }

    int tmp;
    if(mnds == ds[x]) {
        while(true) {
            tmp = s.top(); s.pop();
            scc[tmp] = scc_cnt;
            if(x == tmp) break;
        }
        scc_cnt++;
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
    for(int i=0; i<n; i++) {
        cout << i << ": "<< scc[i] << "\n";
    }
    return 0;
}
