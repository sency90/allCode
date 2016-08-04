#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
int n,m,s,e;
vector<int> v,d;
int init(int r, int s, int e) {
    if(s==e) return d[r] = v[s];
    else return d[r] = min(init(2*r, s, (s+e)/2), init(2*r+1, (s+e)/2+1, e));
}
int query(int r, int s, int e, int i, int j) {
    if(j<s || i>e) return inf;
    if(i<=s && e<=j) return d[r];
    return min(query(2*r,s,(s+e)/2,i,j), query(2*r+1,(s+e)/2+1,e,i,j));
}
int query(int i, int j) {
    return query(1,1,n,i,j);
}
int main() {
    scanf("%d%d",&n,&m);
    v.resize(n+1);
    d.resize(n*4,inf);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    init(1,1,n);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&s,&e);
        printf("%d\n", query(s,e));
    }
    return 0;
}
