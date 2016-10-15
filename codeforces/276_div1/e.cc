#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
struct Query{
    int x,y,w;
    Query(int x, int y, int w):x(x),y(y),w(w){}
};
struct Info{
    int f,r,mx,sz; Info(){} Info(int f, int r, int mx, int sz):f(f),r(r),mx(mx),sz(sz){}
    Info operator+(const Info &rhs) {
        Info info(f+rhs.f,r+rhs.r,mx+rhs.mx,sz+rhs.sz);
        return info;
    }
    Info operator&(const Info &rhs) {
        Info info;
        info.sz=sz+rhs.sz;
        info.f=f; info.r=rhs.r;
        if(f==sz) info.f=sz+rhs.f;
        if(rhs.r==rhs.sz) info.r=r+rhs.sz;
        info.mx = max({r+rhs.f, mx, rhs.mx, info.f, info.r});
        return info;
    }
    void println() {
        printf("f:%d r:%d mx:%d sz:%d\n",f,r,mx,sz);
    }
};
struct Seg{
    int s,e;
    vector<Info> tree;
    Seg(int n):s(0){
        for(e=0; (1<<e)<n; e++);
        tree.clear(); tree.resize(1<<(e+1),Info(0,0,0,1));
        e=n-1;
    }
    Info init(int r, int s, int e) {
        if(s==e) return tree[r]=Info(0,0,0,1);
        return tree[r]=init(r<<1,s,(s+e)>>1)+init((r<<1)|1,((s+e)>>1)+1,e);
    }
    Info update(int r, int s, int e, int idx) {
        if(idx<s||e<idx) return tree[r];
        if(s==e) return tree[r]=Info(1,1,1,1);
        return tree[r]=update(r<<1,s,(s+e)>>1,idx)&update((r<<1)|1,((s+e)>>1)+1,e,idx);
    }
    Info query(int r, int s, int e, int qs, int qe) {
        if(qe<s||e<qs) return Info(0,0,0,1);
        else if(qs<=s&&e<=qe) return tree[r];
        return query(r*2,s,(s+e)/2,qs,qe)&query(r*2+1,(s+e)/2+1,e,qs,qe);
    }
};
vector<Query> q;
vector<pii> h, range;
vector<int> ans;
bool cmp(const pii &l, pii &r) {
    if(l.first==r.first) return l.second<r.second;
    else return l.first>r.first;
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int hh; scanf("%d", &hh);
        h.push_back(make_pair(hh,i));
    }
    sort(h.begin(), h.end(), cmp);

    int m; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        x--; y--;
        q.push_back(Query(x,y,w));
        range.push_back(make_pair(0,n-1));
    }
    ans.resize(m);

    Seg seg(n);
    seg.init(1,seg.s,seg.e);
    vector<vector<int> > wc(n, vector<int>());
    while(true) {
        bool good=false;
        for(int z=0; z<m; z++) {
            if(range[z].first<=range[z].second) {
                wc[(range[z].first+range[z].second)>>1].push_back(z);
                good=true;
            }
        }
        if(!good) break;
        for(int i=0; i<h.size(); i++) {
            seg.update(1,seg.s,seg.e,h[i].second);
            for(auto &p: wc[i]) {
                int mxw = seg.query(1,seg.s,seg.e,q[p].x,q[p].y).mx;
                if(q[p].w<=mxw) {
                    ans[p]=max(ans[p],h[i].first);
                    range[p].second=i-1;
                } else range[p].first=i+1;
            }
        }
        for(int i=0; i<n; i++) wc[i].clear();
        seg.init(1,seg.s,seg.e);
    }
    for(auto &p: ans) printf("%d\n", p);
    return 0;
}
