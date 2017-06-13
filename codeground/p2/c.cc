#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int cntx[100001],cnty[100001],conn[100001],ytox[100001],cx[100001],color[100001];
inline void fio(int *a) {
    register char c=0;
    while(c<33) c=getchar_unlocked();
    *a=0;
    while(c>33) {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}
struct Info {
    int b,r,mx;
    Info() {}
    Info(int b,int r,int mx) :b(b),r(r),mx(mx) {}
    Info operator&(const Info &rhs) {
        return Info(b+rhs.b,r+rhs.r,max(b+rhs.mx,mx+rhs.r));
    }
};
vector<Info> tr(1<<18);
struct Seg {
    int s,e;
    vector<Info> &tree;
    Seg(int n) :s(0),e(n-1),tree(tr) {}
    Info init(int r,int s,int e) {
        if(s==e) {
            if(color[s]) return tree[r]=Info(1,0,1);
            else return tree[r]=Info(0,1,1);
        }
        return tree[r]=init(r<<1,s,(s+e)>>1)&init((r<<1)|1,((s+e)>>1)+1,e);
    }
    Info update(int r,int s,int e,int idx) {
        if(idx<s||e<idx) return tree[r];
        else if(s==e) {
            if(color[s]) return tree[r]=Info(0,1,1);
            else return tree[r]=Info(1,0,1);
        }
        return tree[r]=update(r<<1,s,(s+e)>>1,idx)&update((r<<1)|1,((s+e)>>1)+1,e,idx);
    }
};
int main() {
    setbuf(stdout,NULL);
    int tc; fio(&tc);
    for(int z=1; z<=tc; z++) {
        int n; fio(&n);
        memset(cx,-1,sizeof(cx));
        memset(cntx,0,sizeof(cntx));
        memset(cnty,0,sizeof(cnty));
        memset(conn,0,sizeof(conn));
        memset(ytox,0,sizeof(ytox));
        memset(color,0,sizeof(color));
        for(int i=0; i<n; i++) {
            int x,y,c;
            fio(&x);fio(&y);fio(&c);
            cnty[y]++; cntx[x]++;
            conn[y]=x;
            cx[x]=c;
        }

        //counting sort
        for(int i=1; i<=100000; i++) {
            cntx[i]+=cntx[i-1];
            cnty[i]+=cnty[i-1];
        }
        for(int i=100000; i>=1; i--) {
            ytox[--cnty[i]]=cntx[conn[i]]-1;
            if(cx[i]>=0) color[cntx[i]-1]=cx[i];
        }

        int mx=0;
        Seg seg(n);
        seg.init(1,seg.s,seg.e);
        for(int i=0; i<n; i++) mx=max(mx, seg.update(1,seg.s,seg.e,ytox[i]).mx);
        printf("Case #%d\n%d\n",z,mx);
    }
    return 0;
}
