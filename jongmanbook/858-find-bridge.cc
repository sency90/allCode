#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 9
using namespace std;
typedef pair<int,int> pii;
vector<pii> g[N],br;
vector<int> v[N];
bool chk[N];
int discov[N];
void e(int x, int y) {
    v[x].push_back(y);
    v[y].push_back(x);
}
int cnt=0;
const int inf = 0x3f3f3f3f;
int dfs(int x, int p) {
    discov[x]=++cnt;
    int ret = inf;
    for(auto y: g[x]) {
        if(discov[y.first]) {
            if(p==y.first && y.second==1) continue;
            ret = min(ret, discov[y.first]);
        } else {
            int subtree = dfs(y.first,x);
            if(subtree>discov[x] && y.second==1) br.push_back({x,y.first});
            ret = min(ret, subtree);
        }
    }
    return min(ret,discov[x]);
}
int main() {
    int n=N;
    e(0,1);
    //e(0,4);
    e(3,7);
    e(0,5);
    e(0,6);
    e(5,3);
    e(5,6);
    e(2,4);
    e(4,8);
    e(2,4);
    //e(6,3);
    e(4,2);
    e(1,2);
    e(2,0);
    e(3,7);
    for(int i=0; i<n; i++) {
        memset(chk,0,sizeof(chk));
        sort(v[i].begin(),v[i].end());
        int pj=-1;
        for(int j: v[i]) {
            if(pj!=j) g[i].push_back({j,1});
            else (g[i].end()-1)->second++;
            pj=j;
        }
    }
    dfs(0,-1);
    puts("Bridge: ");
    for(auto &y: br) printf("(%d,%d) ", y.first, y.second);
    puts("");
    return 0;
}
