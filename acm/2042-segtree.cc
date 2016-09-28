#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> tree;
int f(int n) {
    int exp=0;
    for(int i=0; i<n; i++) {
        if((1<<i)>=n) { exp=i; break; }
    }
    tree.clear(); tree.resize((1<<(exp+1)));
    return (1<<exp);
}
long long update(int r, int s, int e, int idx, int x) {
    if(idx<s||e<idx) return tree[r];
    if(s==e) return tree[r]=x;
    return tree[r] = update(2*r,s,(s+e)/2,idx,x) + update(2*r+1,(s+e)/2+1,e,idx,x);
}
long long query(int r, int s, int e, int qs, int qe) {
    if(qe<s||e<qs) return 0LL;
    if(qs<=s&&e<=qe) return tree[r];
    else return query(r*2,s,(s+e)/2,qs,qe)+query(r*2+1,(s+e)/2+1,e,qs,qe);
}
int main() {
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    int s=1, e=f(n), x;
    //tree.clear(); tree.resize(4*n,0);
    for(int i=1; i<=n; i++) {
        scanf("%d",&x);
        update(1,s,e,i,x);
    }
    int lim = m+k, a,b,c;
    for(int i=0; i<lim; i++) {
        scanf("%d%d%d",&a,&b,&c);
        if(a==1) update(1,s,e,b,c);
        else printf("%lld\n", query(1,s,e,b,c));
    }
    return 0;
}
