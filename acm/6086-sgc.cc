#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
 
using namespace std;
 
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
 
const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;
int n;
 
vi adj[220];
int cap[220][220],flow[220][220];
int parent[220];
 
int edmonds(int start, int finish) {
    int ret = 0;
 
    while(true) {
        queue<int> q;
        q.push(start);
        memset(parent,-1,sizeof(parent));
        parent[start]=start;
        while(!q.empty() && parent[finish] == -1) {
            int here = q.front();
            q.pop();
            for(auto &there : adj[here]) {
                if(cap[here][there]-flow[here][there]>0 && parent[there] == -1) {
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
 
        if(parent[finish] == -1) break;
 
        int minFlow=INF;
        for(int p = finish; p != parent[p]; p = parent[p]) {
            minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
        }
        for(int p = finish; p != parent[p]; p = parent[p]) {
            flow[parent[p]][p] += minFlow;
            flow[p][parent[p]] -= minFlow;
        }
        ret += minFlow;
    }
    return ret;
}
int main() {
    inp1(n);
    FOR(i,n) {
        char a,b;
        int c;
        scanf(" %c %c %d",&a,&b,&c);
        cap[a-'A'][b-'A']+=c;
        adj[a-'A'].pb(b-'A');
        adj[b-'A'].pb(a-'A');
    }
    printf("%d",edmonds('A'-'A','Z'-'A'));
 
    return 0;
}