#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#define N 7
using namespace std;
vector<int> v[N];
stack<int> s;
int scc[N], discov[N];
int cnt=0, scc_cnt=1;
int dfs(int x) {
    s.push(x);
    int mnds;
    discov[x]=mnds=++cnt;
    for(int y: v[x]) {
        if(!discov[y]) mnds = min(mnds,dfs(y));
        else if(scc[y]<0) mnds = min(mnds,discov[y]);
    }

    if(discov[x]==mnds) {
        while(true) {
            int k = s.top(); s.pop();
            scc[k]=scc_cnt;
            if(discov[k]==mnds) break;
        }
        scc_cnt++;
    }
    return mnds;
}
int main() {
    memset(scc,-1,sizeof(scc));
    v[0].push_back(1);
    v[0].push_back(4);
    v[1].push_back(2);
    //v[1].push_back(0);
    v[2].push_back(3);
    v[3].push_back(1);
    v[4].push_back(5);
    v[5].push_back(6);
    v[6].push_back(4);
    dfs(0);

    for(int i=0; i<N; i++) {
        printf("%d: %d\n", i,scc[i]);
    }
    return 0;
}
