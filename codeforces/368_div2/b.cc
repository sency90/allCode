#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
vector<pair<int,int> > ed[100001];
vector<int> tmp;
set<int> chk;
int main() {
    int n,m,k,mn=0x3f3f3f3f,u,v,l;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&u,&v,&l);
        ed[u].push_back(make_pair(v,l));
        ed[v].push_back(make_pair(u,l));
    }
    int x;
    if(k==0) {
        puts("-1");
        return 0;
    }
    for(int i=0; i<k; i++) {
        scanf("%d", &x);
        chk.insert(x);
        tmp.push_back(x);
    }
    for(int i=0; i<tmp.size(); i++) {
        for(int j=0; j<ed[tmp[i]].size(); j++) {
            if(chk.count(ed[tmp[i]][j].first) > 0 ) continue;
            else mn = min(mn, ed[tmp[i]][j].second);
        }
    }
    if(mn==0x3f3f3f3f) puts("-1");
    else printf("%d", mn);
    return 0;
}
