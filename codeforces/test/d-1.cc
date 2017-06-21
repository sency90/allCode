#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define r2 (r<<1)
#define m2 ((s+e)>>1)
typedef pair<int,int> pii;
typedef long long ll;
struct Line{
    int x1,x2,h,v;
    Line(){} Line(int x1, int x2, int h, int v):x1(x1),x2(x2),h(h),v(v){}
    bool operator<(const Line &rhs) const {
        return h<rhs.h;
    }
};
vector<Line> line;
map<int,int> xidx;
set<int> st;
vector<pii> v;
int s,e;
vector<int> tree(800001,0), cover(800001,0);
int idx[200001], num[200001];
void update(int r, int s, int e, int qs, int qe, int v) {
    if(e<=qs||qe<=s) return;
    else if(qs<=s&&e<=qe) {
        cover[r]+=v;
        if(cover[r]) tree[r]=num[e]-num[s];
        else if(s+1==e) tree[r]=0;
        else tree[r]=tree[r2]+tree[r2+1];
    } else {
        update(r2,s,m2,qs,qe,v);
        update(r2+1,m2,e,qs,qe,v);
        if(cover[r]==0) tree[r]=tree[r2]+tree[r2+1];
    }
}
int main() {
    freopen("input.txt","r",stdin);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        st.insert(x1); st.insert(x2+1);
        v.push_back(pii(x1,x2+1));
        line.emplace_back(Line(0,0,y1,+1));
        line.emplace_back(Line(0,0,y2+1,-1));
    }

    int idx=1;
    for(auto &p: st) {
        xidx[p]=idx;
        num[idx]=p;
        idx++;
    }
    for(int i=0; i<v.size(); i++) {
        line[i<<1].x1=line[(i<<1)+1].x1=xidx[v[i].first];
        line[i<<1].x2=line[(i<<1)+1].x2=xidx[v[i].second];
    }
    sort(line.begin(),line.end());
    int ph=0;
    ll area=0;
    s=1; e=idx-1;
    for(int i=0; i<line.size(); i++) {
        area += ll(line[i].h-ph)*tree[1];
        update(1,s,e,line[i].x1,line[i].x2,line[i].v);
        ph=line[i].h;
    }
    printf("%lld\n", area);
    return 0;
}
