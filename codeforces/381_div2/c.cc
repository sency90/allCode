#include <cstdio>
#include <vector>
#include <algorithm>
#include <vector>
#define r2 (r<<1)
#define m2 ((s+e)>>1)
using namespace std;
typedef pair<int,int> pii;
vector<int> v;
vector<pii> w;
struct Seg{
    int s,e;
    vector<int> tree,lazy;
    Seg(int n):s(0) {
        for(e=0; (1<<e)<n; e++);
        tree.clear(); tree.resize((1<<(e+1)), 0);
        lazy.clear(); lazy.resize((1<<(e+1)), 0);
        e=n-1;
        //e=(1<<e);
    }
    void pushdown(int r, int s, int e) {
        if(lazy[r]) {
            if(s!=e) {
                lazy[r*2]+=lazy[r];
                lazy[r*2]+=lazy[r];
            } else tree[r]+=lazy[r];
            lazy[r]=0;
        }
    }
    int update(int r, int s, int e, int qs, int qe, int x) {
        if(qe<s||e<qs) {
            pushdown(r,s,e);
            return tree[r];
        } else if(s==e) {
            lazy[r]+=x;
            pushdown(r,s,e);
            return tree[r];
        } else return tree[r]=min(update(r2,s,m2,qs,qe,x),update(r2+1,m2+1,e,qs,qe,x));
    }
    void query(int r, int s, int e, int qs, int qe) {
        pushdown(r,s,e);
        if(qe<s||e<qs) return;
        else if(s==e) v.push_back(tree[r]);
        else {
            query(r2,s,m2,qs,qe);
            query(r2+1,m2+1,e,qs,qe);
        }
    }
};
int main() {
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    Seg seg(n);

    for(int i=0; i<m; i++) {
        scanf("%d%d", &l,&r);
        l--; r--;
        seg.update(1,seg.s,seg.e,l,r,1);
    }

    for(int i=0; i<n; i++) {
        seg.query(1,seg.s,seg.e,i,i);
    }

    for(int i=0; i<n; i++) {
        w.push_back({v[i],i});
    }

    auto cmp = [&](const pii &l, const pii &r) -> bool{
        if(l.first==r.first) return l.second<r.second;
        else return l.first>r.first;
    };

    sort(w.begin(),w.end(),cmp);

    for(int i=0; i<n; i++) {
        pw = w[i].first;
    }
    return 0;
}
