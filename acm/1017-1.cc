#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool notPrime[2001], chk[2001];
int aM[2001], bM[2001];
vector<int> g[2], v[2001], m;
bool bipartite(int x) {
    if(chk[x]) return false;
    chk[x]=true;
    for(auto &y: v[x]) {
        if(bM[y]==-1||bipartite(bM[y])) {
            bM[y]=x;
            aM[x]=y;
            return true;
        }
    }
    return false;
}
int main() {
    int n,x; scanf("%d", &n);
    notPrime[0]=notPrime[1]=true;
    for(int i=2; i*i<=2000; i++) {
        if(notPrime[i]) continue;
        for(int j=i*i; j<=2000; j+=i) {
            notPrime[j]=true;
        }
    }
    int t=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        if(i==0) t=x&1;
        g[t^(x&1)].push_back(x);
    }
    if(g[0].size()!=g[1].size()) {
        puts("-1"); return 0;
    }

    vector<int> f;
    for(int i=0; i<g[0].size(); i++) {
        for(int j=0; j<g[1].size(); j++) {
            if(notPrime[g[0][i]+g[1][j]]) continue;
            if(i==0) f.push_back(j);
            else v[i].push_back(j);
        }
    }

    bool isFirst=true;
    for(auto &p: f) {
        memset(bM,-1,sizeof(bM));
        if(isFirst) {
            isFirst=false;
            v[0].push_back(p);
        } else v[0][0]=p;
        int ans=0;
        for(int i=0; i<g[0].size(); i++) {
            memset(chk,false,sizeof(chk));
            if(bipartite(i)) ans++;
            else break;
        }
        if(ans*2==n) m.push_back(g[1][p]);
    }
    if(m.empty()) {
        puts("-1");
        return 0;
    }
    sort(m.begin(), m.end());
    for(auto &p: m) printf("%d ", p);
    return 0;
}
