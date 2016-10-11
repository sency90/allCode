#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<pair<int, int> > v;
long long d[100001][2];
int id_x[100001], id_y[100001];
map<int, int> cx, cy;
int main() {
    int n,t=0,cntx=0,cnty=0,x,y,xid,yid;
    long long l,ans=0LL;
    scanf("%d%lld",&n,&l);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&x,&y);
        if(cx.count(x)) xid=cx[x];
        else cx[x]=xid=cntx++;
        if(cy.count(y)) yid=cy[y];
        else cy[y]=yid=cnty++;
        v.push_back(make_pair(xid,yid));
    }
    for(auto &p : cx) id_x[p.second]=p.first;
    for(auto &p : cy) id_y[p.second]=p.first;
    auto cmp = [&](const pair<int,int>& lhs, const pair<int,int>& rhs){
        if(id_x[lhs.first]==id_x[rhs.first]) return id_y[lhs.second]<id_y[rhs.second];
        else return id_x[lhs.first]<id_x[rhs.first];
    };
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; i++) {
        long long dist=abs(id_y[v[i].second]-id_x[v[i].first])+l,tmp;
        tmp=max(d[v[i].first][t],d[v[i].second][t^1]+dist);
        d[v[i].second][t^1]=max(d[v[i].second][t^1],d[v[i].first][t]+dist);
        d[v[i].first][t]=tmp;
        ans=max(ans,d[v[i].first][t]);
        ans=max(ans,d[v[i].second][t^1]);
    }
    printf("%lld\n", ans);
    return 0;
}
