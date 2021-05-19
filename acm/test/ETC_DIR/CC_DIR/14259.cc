#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
set<int> s;
int findcnt(int n, int a) {
    return int((n+1)/(a+1));
}
int main() {
    int n,k,a;
    scanf("%d%d%d",&n,&k,&a);
    int m,x; scanf("%d", &m);
    s.insert(0); s.insert(n+1);
    int r,l,R,L,pv = findcnt(n,a);
    for(int i=1; i<=m; i++) {
        scanf("%d", &x);
        auto it = s.upper_bound(x);
        R=*it;
        r=*it-x-1;
        L=*(--it);
        l=x-*it-1;
        pv = pv - findcnt(R-L-1,a) + findcnt(r,a) + findcnt(l,a);
        s.insert(x);
        //printf("BATTLESHIP:%d (R-L-1):%d l:%d r:%d\n",pv,R-L-1,l,r);
        if(pv<k) return 0&printf("%d\n", i);
    }
    puts("-1");
    return 0;
}
