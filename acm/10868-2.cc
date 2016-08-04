#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct RMQ{
    int n;
    vector<int> v, d;
    RMQ(int n) : n(n) {
        v.resize(n+1);
        d.resize(n*4);
        for(int i=1; i<=n; i++) cin >> v[i];
        init(1,1,n);
    }

    int init(int r, int s, int e) {
        if(s==e) return d[r]=v[s];
        else return d[r] = min(init(2*r,s,(s+e)/2),init(2*r+1,(s+e)/2+1,e));
    }
    int query(int r, int s, int e, int i, int j) {
        if(j<s || e<i) return 0x3f3f3f3f;
        if(i<=s && e<=j) return d[r];
        return min(query(2*r,s,(s+e)/2,i,j),query(2*r+1,(s+e)/2+1,e,i,j));
    }
    int query(int i, int j) {
        return query(1,1,n,i,j);
    }
};
int main() {
    ios::sync_with_stdio(false);
    int n,m,s,e;
    cin >> n >> m;
    RMQ rmq(n);
    for(int i=0; i<m; i++) {
        cin >> s >> e;
        printf("%d\n", rmq.query(s,e));
    }
    return 0;
}
