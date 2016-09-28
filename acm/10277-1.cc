#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
struct Seg{
    int s, e;
    pii defau;
    vector<pii> tree;
    vector<int> lazy;
    Seg(int n):s(1),defau(pii(inf,-1)) {
        for(e=0; (1<<e)<n; e++);
        tree.clear(); tree.resize(1<<(e+1),pii(0,0));
        lazy.clear(); lazy.resize(1<<(e+1),0);
        e=(1<<e);
    }
    void push_down(int r, int s, int e) {
        if(lazy[r]) {
            if(s!=e) {
                lazy[r<<1]+=lazy[r];
                lazy[(r<<1)+1]+=lazy[r];
            }
            tree[r].first += lazy[r];
            tree[r].second += lazy[r];
            lazy[r]=0;
        }
    }
    pii search(int r, int s, int e, int qs, int qe) {
        push_down(r,s,e);
        if(qe<s||e<qs) return defau;
        else if(qs<=s&&e<=qe) return tree[r];
        else {
            int mid = (s+e)>>1;
            pii left=search(r<<1,s,mid,qs,qe), right=search((r<<1)+1,mid+1,e,qs,qe);
            return make_pair(min(left.first,right.first), max(left.second,right.second));
        }
    }
    int query(int r, int s, int e, int idx) {
        push_down(r,s,e);
        if(idx<s||e<idx) return 0;
        if(s==e) return tree[r].second;
        int mid = (s+e)>>1;
        return query(r<<1,s,mid,idx)+query((r<<1)+1,mid+1,e,idx);
    }
    pii update(int r, int s, int e, int qs, int qe, int x) {
        push_down(r,s,e);
        if(qe<s||e<qs) return tree[r];
        else if(qs<=s&&e<=qe) {
            lazy[r]+=x;
            push_down(r,s,e);
            return tree[r];
        } else {
            int mid = (s+e)>>1;
            pii left=update(r<<1,s,mid,qs,qe,x), right=update((r<<1)+1,mid+1,e,qs,qe,x);
            tree[r].first = min(left.first,right.first);
            tree[r].second = max(left.second,right.second);
            return tree[r];
        }
    }
};
int calcDiff(pii &diff, int x, int lim) {
    if(x<0) return -min(diff.first,-x);
    else if(diff.second+x>lim) return lim-diff.second;
    else return x;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int c,n,o,x,a,b;
    cin>>c>>n>>o;
    Seg seg(c);
    string type;
    for(int i=0; i<o; i++) {
        cin>>type;
        if(type[0]=='s') {
            cin >>a;
            printf("%d\n", seg.query(1,seg.s,seg.e,a+1));
        } else if(type[0]=='c') {
            cin >>a>>x;
            pii diff = seg.search(1,seg.s,seg.e,a+1,a+1);
            int ans = calcDiff(diff,x,n);
            printf("%d\n",ans);
            seg.update(1,seg.s,seg.e,a+1,a+1,ans);
        } else {
            cin >>a>>b>>x;
            pii diff = seg.search(1,seg.s,seg.e,a+1,b+1);
            int ans = calcDiff(diff,x,n);
            printf("%d\n",ans);
            seg.update(1,seg.s,seg.e,a+1,b+1,ans);
        }
    }
    return 0;
}
