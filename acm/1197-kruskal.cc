#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,pair<int,int> > > v;
int p[10001];
void init(int n) {
    for(int i=0; i<=n; i++) p[i]=i;
}
int find(int x) {
    if(p[x]==x) return x;
    else return p[x] = find(p[x]);
}
bool uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    p[y]=x;
    return true;
}
int main() {
    int n,m,s,e,w;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
            scanf("%d%d%d",&s,&e,&w);
            v.push_back(make_pair(w, make_pair(s,e)));
        }
    init(n);
    int ans=0;
    sort(v.begin(), v.end());
    for(auto &ed : v) {
            w=ed.first; s=ed.second.first; e=ed.second.second;
            if(uni(s,e)) ans+=w;
        }
    printf("%d", ans);
    return 0;
}
