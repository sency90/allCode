#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int v[100001], g[370];
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    memset(g, 0x3f, sizeof(g));
    int x = sqrt(n);
    for(int i=0; i<n; i++) {
        scanf("%d", v+i);
        g[i/x] = min(g[i/x], v[i]);
    }

    int a, b, mn, ae, bs, s, e;
    for(int i=0; i<m; i++) {
        mn = 0x3f3f3f3f;
        scanf("%d%d",&a,&b);
        a--; b--;
        if(a>b) swap(a,b);

        ae = (a/x+1)*x; bs=(b/x)*x;
        s = ae/x; e = bs/x;
        for(int i=s; i<e; i++) {
            if(mn>g[i]) mn = g[i];
        }

        if(ae<bs) {
            for(int i=a; i<ae; i++) {
                if(mn>v[i]) mn = v[i];
            }
            for(int i=bs; i<=b; i++) {
                if(mn>v[i]) mn = v[i];
            }
        } else {
            for(int i=a; i<=b; i++) {
                if(mn>v[i]) mn = v[i];
            }
        }
        printf("%d\n", mn);
    }
    return 0;
}
