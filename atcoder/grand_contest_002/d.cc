#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
//vector<pair<int, pii> > ed;
vector<pii> ed;
vector<int> wc[100001];
int p[100001], l[100001], r[100001], ans[100001], cnt[100001];
struct Query{
    int x,y,z;
    Query(){} Query(int x, int y, int z):x(x),y(y),z(z) {}
};
void init(int n) {
    for(int i=0; i<=n; i++) {
        p[i]=i;
        cnt[i]=1;
    }
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
        cnt[x]+=cnt[y];
        return true;
    }
}
int main() {
    int n,m,x,y,z;
    scanf("%d%d",&n,&m);
    vector<pii> ed(m+1, pii());
    for(int i=1; i<=m; i++) {
        scanf("%d%d",&x,&y);
        ed[i]=make_pair(x,y);
        //ed.push_back(make_pair(i,make_pair(x,y)));
    }
    int qsz;
    scanf("%d", &qsz);
    vector<Query> q(qsz+1, Query());
    for(int i=1; i<=qsz; i++) {
        scanf("%d%d%d",&x,&y,&z);
        q[i]=Query(x,y,z);
        l[i]=1; r[i]=m;
    }
    while(true) {
        bool isIn=false;
        init(n+1);
        for(int qidx=1; qidx<=qsz; qidx++) {
            if(l[qidx]<=r[qidx]) {
                wc[(l[qidx]+r[qidx])/2].push_back(qidx);
                isIn=true;
            }
        }
        if(!isIn) break;
        for(int i=1; i<=m; i++) {
            uni(ed[i].first, ed[i].second);
            for(auto &qidx : wc[i]) {
                int u=find(q[qidx].x), v=find(q[qidx].y);
                int count=(u==v)?cnt[u]:cnt[u]+cnt[v];
                if(count>=q[qidx].z) { //ans
                    r[qidx]=i-1;
                    ans[qidx]=i;
                } else {
                    l[qidx]=i+1;
                }
            }
        }
        for(int i=0; i<=m; i++) wc[i].clear();
    }
    for(int i=1; i<=qsz; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
