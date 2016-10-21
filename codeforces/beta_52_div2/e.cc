#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define r2 (r<<1)
#define mid ((s+e)>>1)
using namespace std; struct Info{
    int x,xh,idx,oIdx;
    Info(){} Info(int x, int xh, int idx, int oIdx):x(x),xh(xh),idx(idx),oIdx(oIdx) {}
    bool operator<(const Info &rhs) const {
        return x<rhs.x;
    }
    void println() {
        printf("x:%d, xh:%d, idx:%d, oIdx:%d\n",x,xh,idx,oIdx);
    }
};
const int inf = 0x3f3f3f3f;
Info none(-inf,-inf,-inf,-inf);
vector<Info> v;
struct Seg{
    int s, e;
    vector<Info> tree;
    Seg(int n):s(0){
        for(e=0; (1<<e)<n; e++);
        tree.resize((1<<(e+1)));
        e=n-1;
    }

    Info init(int r, int s, int e) {
        if(s==e) return tree[r]=v[s];
        else {
            Info linfo=init(r2,s,mid), rinfo=init(r2+1,mid+1,e);
            if(linfo.xh>rinfo.xh) return tree[r]=linfo;
            else return tree[r]=rinfo;
        }
    }

    Info query(int r, int s, int e, int qs, int qe) {
        if(qe<s||e<qs) return none;
        else if(qs<=s&&e<=qe) return tree[r];
        else {
            Info linfo=query(r2,s,mid,qs,qe), rinfo=query(r2+1,mid+1,e,qs,qe);
            if(linfo.xh>rinfo.xh) return linfo;
            else return rinfo;
        }
    }
};
int ans[100001];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x,h;
        scanf("%d%d",&x,&h);
        v.push_back(Info(x,x+h,0,i));
        ans[i]=1;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) v[i].idx=i;
    Seg seg(n);
    seg.init(1,seg.s,seg.e);
    for(int i=n-1; i>=0; i--) {
        auto it = lower_bound(v.begin(), v.end(), Info(v[i].xh,-inf,-inf,-inf));
        int idx = it-v.begin();
        if(i+1>idx-1) continue;
        Info info = seg.query(1,seg.s,seg.e,i+1,idx-1);
        ans[v[i].oIdx]=(info.idx-i)+ans[info.oIdx];
    }
    for(int i=0; i<n; i++) printf("%d ", ans[i]);
    return 0;
}
