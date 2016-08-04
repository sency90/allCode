#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> h;
struct RMQ{
    int n, isMn, inf;
    vector<int> d;
    RMQ(int n, int mn) : n(n), isMn(mn) {
        d.resize(4*n);
        if(mn<0) inf=0;
        else inf=0x3f3f3f3f;
        init(1,0,n-1,mn);
    }

    int init(int r, int s, int e, int mn) {
        if(s==e) return d[r]=mn*h[s];
        else return d[r] = min(init(r*2,s,(s+e)/2,mn), init(r*2+1,(s+e)/2+1,e,mn));
    }

    int query(int r, int s, int e, int i, int j) {
        if(j<s || i>e) return inf;
        if(i<=s && e<=j) return d[r];
        return min(query(r*2,s,(s+e)/2,i,j), query(r*2+1,(s+e)/2+1,e,i,j));
    }

    int query(int i, int j) {
        return query(1,0,n-1,i,j);
    }
};
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n, q, s, e;
        scanf("%d%d",&n,&q);
        h.clear();
        h.resize(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &h[i]);
        }
        RMQ mx(n,-1), mn(n,1);
        for(int i=0; i<q; i++) {
            scanf("%d%d",&s,&e);
            printf("%d\n",-mx.query(s,e)-mn.query(s,e));
        }
    }
    return 0;
}
