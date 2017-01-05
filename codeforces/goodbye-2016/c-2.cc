#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
    int n; scanf("%d", &n);
    int mx=inf, mn=-inf;

    int pos=0;
    for(int i=0; i<n; i++) {
        int c,d; scanf("%d%d",&c,&d);
        if(d==1) mn=max(mn,1900-pos);
        else mx=min(mx,1899-pos);
        pos+=c;
    }

    if(mx<mn) puts("Impossible");
    else if(mx>=inf) puts("Infinity");
    else printf("%d\n", mx+pos);
    return 0;
}
