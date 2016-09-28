#include <cstdio>
#include <vector>
using namespace std;
struct Seg{
    int s,e;
    vector<long long> tree;
    Seg(int n):s(1) {
        for(e=0; (1<<e)<n; e++);
        tree.clear(); tree.resize((1<<(e+1)), 0);
        e=1<<e;
    }
    long long update(int r, int s, int e, int idx, long long x) {
        if(idx<s||e<idx) return tree[r];
        if(s==e) return tree[r]=x;
        int mid = (s+e)>>1;
        return tree[r] = update(r<<1,s,mid,idx,x)+update((r<<1)+1,mid+1,e,idx,x);
    }
    long long query(int r, int s, int e, int qs, int qe) {
        if(qe<s||e<qs) return 0LL;
        if(qs<=s&&e<=qe) return tree[r];
        int mid=(s+e)>>1;
        return query(r<<1,s,mid,qs,qe)+query((r<<1)+1,mid+1,e,qs,qe);
    }
};
int main() {
    int n,m,k,d;
    scanf("%d%d%d",&n,&m,&k);
    Seg seg(n);

    for(int i=1; i<=n; i++) {
        scanf("%d", &d);
        seg.update(1,seg.s,seg.e,i,d);
    }
    int a,b,lim=m+k;
    long long c;
    for(int i=0; i<lim; i++) {
        scanf("%d%d%lld",&a,&b,&c);
        if(a==1) seg.update(1,seg.s,seg.e,b,c);
        else printf("%lld\n",seg.query(1,seg.s,seg.e,b,c));
    }
    return 0;
}
