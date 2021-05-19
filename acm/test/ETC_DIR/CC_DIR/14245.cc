#include <cstdio>
#include <vector>
using namespace std;
#define r2 (r<<1)
#define m2 ((s+e)>>1)
vector<int> v;
struct Seg{
    int s, e;
    vector<int> tree, lazy;
    Seg(int n):s(1) {
        for(e=0; (1<<e)<n; e++);
        tree.clear(); tree.resize((1<<(e+1)),0);
        lazy.clear(); lazy.resize((1<<(e+1)),0);
        e=1<<e;
    }
    int init(int r, int s, int e) {
        if(s==e) return tree[r]=v[s];
        else return tree[r]=init(r2,s,m2)^init(r2+1,m2+1,e);
    }
    void push_down(int r, int s, int e) {
        if(lazy[r]) {
            if(s==e) tree[r]^=lazy[r];
            else {
                lazy[r2]^=lazy[r];
                lazy[r2+1]^=lazy[r];
            }
            lazy[r]=0;
        }
    }
    int update(int r, int s, int e, int qs, int qe, int x) {
        if(qe<s||e<qs) {
            push_down(r,s,e);
            return tree[r];
        } else if(qs<=s&&e<=qe) {
            lazy[r]^=x;
            push_down(r,s,e);
            return tree[r];
        } else return tree[r]=update(r2,s,m2,qs,qe,x)^update(r2+1,m2+1,e,qs,qe,x);
    }
    int query(int r, int s, int e, int idx) {
        push_down(r,s,e);
        if(idx<s||e<idx) return 0;
        else if(idx<=s&&e<=idx) return tree[r];
        else return query(r2,s,m2,idx)+query(r2+1,m2+1,e,idx);
    }
};
int main() {
    int n; scanf("%d", &n);
    Seg seg(n);
    v.clear(); v.resize(seg.e+1,0);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    seg.init(1,seg.s,seg.e);
    int m,type; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d",&type);
        int a,b,c;
        if(type==1) {
            scanf("%d%d%d",&a,&b,&c);
            seg.update(1,seg.s,seg.e,min(a,b)+1,max(a,b)+1,c);
        } else {
            scanf("%d",&a);
            printf("%d\n", seg.query(1,seg.s,seg.e,a+1));
        }
    }
    return 0;
}
