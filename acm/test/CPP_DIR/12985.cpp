#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct Vertex{
    int val, x;
    Vertex() {}
    Vertex(int vval, int xx) {val=vval;x=xx}
    bool operator<(const Vertex& rhs) const {
        return val < rhs.val;
    }
};
vector<Vertex> co;
int d[200001];
long long abs(long long x) {
    return (x<0LL)?-x:x;
}
/*
int init(int x, int s, int e) {
    if(s==e) return d[x] = v[s];
    return d[x] = max(init(x*2, s, (s+e)/2), init(x*2+1, (s+e)/2+1, e));
}
int query(int x, int s, int e, int i, int j) {
    if(i>e || j<s) return -1;
    if(i<=s && e<=j) return d[x];
    return max(query(2*x, s, (s+e)/2, i, j), query(2*x+1, (s+e)/2+1,e,i,j));
}
*/
int main() {
    int n,x,value;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&value,&x);
        co.push_back(Vertex(value,x));
    }
    sort(co.begin(), co.end());
    long long res = 0LL;
    //init(1,1,n);
    for(int i=0; i<n-1; i++) {
        co[i].x
        res += abs(co[j].x-co[i].x)*co[i].val;//query(1,1,n,i,j);
    }
    printf("%lld", res);

    return 0;
}
