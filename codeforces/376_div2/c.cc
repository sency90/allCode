#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
int p[200001], scolor[200001], tcnt[200001];
int find(int x) {
    if(x==p[x]) return x;
    else return p[x]=find(p[x]);
}
bool uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    else {
        if(x>y) swap(x,y);
        p[y]=x;
        return true;
    }
}
bool chk[200001];
vector<vector<int> > g;
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++) {
        scanf("%d", &scolor[i]);
        p[i]=i;
    }
    for(int i=0; i<m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        tcnt[x]++;
        tcnt[y]++;
        uni(x,y);
    }
    g.clear(); g.resize(n, vector<int>());
    for(int i=0; i<n; i++) {
        if(p[i]!=i) {
            if(g[p[i]].size()==0) {
                    g[p[i]].push_back(p[i]);
            }
            for(int j=0; j<tcnt[i]; j++) {
                g[p[i]].push_back(i);
            }
        }
    }
    int mx=0,ans=0;
    for(int i=0; i<n; i++) {
        if(g[i].size()==0) continue;
        else {
            memset(chk,false,sizeof(chk));
            mx=0;
            map<int,int> mp;
            int cnt=0;
            for(auto &p: g[i]) {
                if(chk[p]) continue;
                chk[p]=true;
                mp[scolor[p]]++;
            }
            for(auto &p: mp) {
                if(mx<p.second) {
                    mx=p.second;
                }
            }
            printf("%d %d\n", cnt,mx);
            ans+=cnt-mx;
        }
    }
    printf("%d", ans);
    return 0;
}
