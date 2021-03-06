#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
const int inf = 0x3f3f3f3f;
struct Seg{
    vector<int> tree;
    Seg(int e) {
        int i;
        for(i=0; (1<<i)<e; i++);
        tree.clear(); tree.resize(1<<(i+1));
    }
    int init(int r, int s, int e) {
        if(s==e) return tree[r]=v[s];
        else return tree[r] = min(init(r<<1,s,(s+e)>>1),init((r<<1)+1,((s+e)>>1)+1,e));
    }
    int update(int r, int s, int e, int idx, int x) {
        if(idx<s||e<idx) return inf;
        if(s==e) return tree[r]=x;
        return tree[r] = min(tree[r], min(update(r<<1,s,(s+e)>>1,idx,x), update((r<<1)+1,((s+e)>>1)+1,e,idx,x)));
    }
    int query(int r, int s, int e, int qs, int qe) {
        if(qe<s||e<qs) return inf;
        if(qs<=s&&e<=qe) return tree[r];
        return min(query(r<<1,s,(s+e)>>1,qs,qe), query((r<<1)+1,((s+e)>>1)+1,e,qs,qe));
    }
};
int main() {
    int n,m,qs,qe;
    scanf("%d%d", &n,&m);
    Seg seg(n);
    v.resize(n+1);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    seg.init(1,1,n);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&qs,&qe);
        printf("%d\n", seg.query(1,1,n,qs,qe));
    }
    return 0;
}
