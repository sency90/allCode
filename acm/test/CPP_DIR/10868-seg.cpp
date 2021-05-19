#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int d[262144];
vector<int> v;
int init(int x, int s, int e) {
    if(s==e) return d[x] = v[s];
    return d[x] = min(init(x*2, s, (s+e)/2), init(x*2+1, (s+e)/2+1, e));
}
int query(int x, int s, int e, int i, int j) {
    if(j<s || i>e) return INF;
    if(i<=s && e<=j) return d[x];
    return min(query(2*x,s,(s+e)/2,i,j), query(2*x+1,(s+e)/2+1,e,i,j));
}
int main() {
    int n, m, a, b;
    scanf("%d%d", &n,&m);
    memset(d, 0x3f, sizeof(d));
    v.resize(n+1);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    init(1,1,n);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&a,&b);
        printf("%d\n", query(1,1,n,a,b));
    }
    return 0;
}
