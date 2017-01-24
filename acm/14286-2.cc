#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
vector<pair<int,pii>> ed;
int p[501], tmp[501];
void init(int n) {
    for(int i=0; i<=n; i++) p[i]=i;
}
int find(int x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
bool uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    else {
        p[y]=x;
        return true;
    }
}
int main() {
    int n,m,sum=0; scanf("%d%d",&n,&m);
    init(n);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        sum+=x;
        ed.push_back(make_pair(w,make_pair(x,y)));
    }
    auto cmp = [](pair<int,pii> &i, pair<int,pii> &j) {
        return i.first>j.first;
    };
    sort(ed.begin(), ed.end(), cmp);
    int s,e,ans=0;
    scanf("%d%d",&s,&e);
    for(auto &u: ed) {
        int w=u.first, x=u.second.first, y=u.second.second;
        memcpy(tmp,p,sizeof(p));
        if(!uni(x,y)) ans+=w;
        else {
            if(find(s)!=find(e)) ans+=w;
            else {
                memcpy(p,tmp,sizeof(tmp));
            }
        }
    }
    printf("%d", sum-ans);
    return 0;
}
