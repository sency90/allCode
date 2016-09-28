#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef pair<int,int> pii;
struct Seg{
    int s, e, lim;
    pii defau;
    vector<pii> tree;
    vector<int> lazy;
    Seg(int n, int lim):s(1),lim(lim),defau(pii(inf,-1)) {
        for(e=0; (1<<e)<n; e++);
        tree.clear(); tree.resize(1<<(e+1),pii(0,0));
        lazy.clear(); lazy.resize(1<<(e+1),0);
        e=(1<<e);
    }
    void push_down(int r, int s, int e) {
        if(lazy[r]) {
            if(s!=e) {
                lazy[r*2]+=lazy[r];
                lazy[r*2+1]+=lazy[r];
            }
            tree[r].first+=lazy[r];
            tree[r].second+=lazy[r];
            lazy[r]=0;
        }
    }
    pii search(int r, int s, int e, int qs, int qe) {
        push_down(r,s,e);
        if(qe<s||e<qs) return defau;
        if(qs<=s&&e<=qe) return tree[r];
        else {
            pii left = search(r*2,s,(s+e)/2,qs,qe);
            pii right = search(r*2+1,(s+e)/2+1,e,qs,qe);
            return make_pair(min(left.first,right.first), max(left.second,right.second));
        }
    }
    pii update(int r, int s, int e, int qs, int qe, int x) {
        push_down(r,s,e);
        if(qe<s||e<qs) return tree[r];//push_down(r,s,e);
        else if(qs<=s&&e<=qe) {
            lazy[r]+=x;
            push_down(r,s,e);
        } else {
            pii left = update(r*2,s,(s+e)/2,qs,qe,x);
            pii right = update(r*2+1,(s+e)/2+1,e,qs,qe,x);
            tree[r].first=min(left.first,right.first);
            tree[r].second=max(left.second,right.second);
        }
        return tree[r];
    }
    int query(int r, int s, int e, int idx) {
        push_down(r,s,e);
        if(idx<s||e<idx) return 0;
        if(s==e) return tree[r].second;
        else return query(r*2,s,(s+e)/2,idx)+query(r*2+1,(s+e)/2+1,e,idx);
    }
};
int calcDiff(pii &cur, int s, Seg &seg) {
    if(s<0) return -min(-s, cur.first);
    else if(s+cur.second<=seg.lim) return s;
    else return seg.lim-cur.second;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string type;
    int c,n,o,a,b,x,s;
    cin >>c>>n>>o;
    Seg seg(c,n);
    for(int i=0; i<o; i++) {
        cin >> type;
        if(type=="state") {
            cin >>x;
            printf("%d\n", seg.query(1,seg.s,seg.e,x+1));
        } else if(type=="change") {
            cin >>x>>s;
            pii diff = seg.search(1,seg.s,seg.e,x+1,x+1);
            int ans = calcDiff(diff,s,seg);
            printf("%d\n", ans);
            seg.update(1,seg.s,seg.e,x+1,x+1,ans);
        } else {
            cin >>a>>b>>s;
            pii diff = seg.search(1,seg.s,seg.e,a+1,b+1);
            int ans = calcDiff(diff,s,seg);
            printf("%d\n", ans);
            seg.update(1,seg.s,seg.e,a+1,b+1,ans);
        }
    }
    return 0;
}
