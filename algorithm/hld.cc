#include <cstdio>
#include <vector>
using namespace std;
#define MIN 0
#define r2 (r<<1)
#define m2 ((s+e)>>1)
const int inf = 0x3f3f3f3f;
struct Seg {
    int s,e;
    vector<int> tree;
    Seg(int n):s(0) {
        for(e=0;(1<<e)<n;e++);
        tree.clear(); tree.resize(1<<(e+1,MIN));
        lazy.clear(); lazy.resize(1<<(e+1,MIN));
        e=n-1;
    }
    void push_down(int r, int s, int e) {
        if(lazy[r]!=MIN) {
            if(s!=e) {
                lazy[r2]=max(lazy[r2],lazy[r]);
                lazy[r2+1]=max(lazy[r2],lazy[r]);
            }
            tree[r] = max(lazy[r],tree[r]);
            lazy[r] = MIN;
        }
    }
    int query(int r, int s, int e, int qs, int qe) {
        push_down(r,s,e);
        if(qe<s||e<qs) return MIN;
        else if(qs<=s&&e<=qe) return tree[r];
        else return max(query(r2,s,m2,qs,qe), query(r2,m2+1,e,qs,qe));
    }
}

int main() {

    return 0;
}
