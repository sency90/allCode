#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> v, d;
int init(int r, int s, int e) {
    if(s==e) return d[r] = v[s];
    return d[r] = min(init(2*r,s,(s+e)/2), init(2*r+1,(s+e)/2+1,e));
}
const int inf = 0x3f3f3f3f;
int query(int r, int s, int e, int i, int j) {
    if(j<s || i>e) return inf;
    if(i<=s && e<=j) return d[r];
    return min(query(2*r,s,(s+e)/2,i,j),query(2*r+1,(s+e)/2+1,e,i,j));
}
int query(int i, int j) {
    return query(1,1,n,i,j);
}
int spow(int x) {
    if(x==0) return 1;
    int ret = spow(x/2);
    if(x%2) return ret*ret*2;
    else return ret*ret;
}
int getSize(int x) {
    int cnt=0;
    while(x>0) {x/=2; cnt++;}
    return spow(cnt+1);
}
int main() {
    scanf("%d%d", &n,&m);
    v.resize(n+1);
    int sz = getSize(n+1);
    d.resize(sz+1);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    init(1,1,n);
    int s,e;
    for(int i=0; i<m; i++) {
        scanf("%d%d",&s,&e);
        printf("%d\n",query(s,e));
    }
    return 0;
}
