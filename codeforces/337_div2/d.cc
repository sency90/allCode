#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
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
vector<int> mx;
map<int, int> mxidx;
struct Seg{
    int s,e;
    vector<ll> tree;
    vector<int> cover;
    Seg(int n):s(0){
        for(e=0; (1<<e)<=n; e++);
        tree.clear(); tree.resize((1<<(e+1)),0);
        cover.clear(); cover.resize(1<<(e+1),0);
        e=n-1;
    }
    void update(int r, int s, int e, int qs, int qe, int v) {
        if(qe<=s||e<=qs) return;
        else if(qs<=s&&e<=qe) {
            cover[r]+=v;
            if(cover[r]==1) tree[r]=mx[e]-mx[s];
            else if(cover[r]==0) {
                if(s+1==e) tree[r]=0;
                else tree[r]=tree[r<<1]+tree[(r<<1)|1];
            }
            return;
        }
        update(r<<1,s,(s+e)>>1,qs,qe,v); update((r<<1)|1,(s+e)>>1,e,qs,qe,v);
        if(cover[r]==0) tree[r]=tree[r<<1]+tree[(r<<1)|1];
    }
};
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        line.push_back(Line(x1,x2+1,y1,1));
        line.push_back(Line(x1,x2+1,y2+1,-1));
        mxidx[x1]++; mxidx[x2+1]++;
    }
    stable_sort(line.begin(),line.end());
    int cnt=0;
    for(auto &p: mxidx) {
        p.second=cnt++;
        mx.push_back(p.first);
    }

    Seg seg(mx.size());
    ll ans=0LL, pH=0LL, pL=0LL;
    for(int i=0; i<line.size(); i++) {
        ans += pL*(line[i].h - pH);
        seg.update(1,seg.s,seg.e,mxidx[line[i].x1],mxidx[line[i].x2],line[i].v);
        pL = seg.tree[1];
        pH = line[i].h;
    }
    printf("%lld\n", ans);
    return 0;
}
