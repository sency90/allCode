#include <stdio.h>
#include <cmath>
#define MAXN 100001
#define GROUP 317
using namespace std;
int gn[MAXN], b[GROUP], e[GROUP];
int c[MAXN], gc[GROUP];
long long gf[GROUP], gfsum[GROUP], f[MAXN];
long long abs(long long x) {
    if(x<0) return -x;
    else return x;
}
int main() {
    long long x;
    int n, m, type, l, r;
    scanf("%d%d",&n,&m);
    int root = sqrt(n);
    for(int i=1; i<=n; i++) {
        c[i]=i; gn[i]=i/root;
        if(!b[gn[i]]) b[gn[i]]=i;
        e[gn[i]]=i;
    }
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&type,&l,&r);
        if(type == 1) {
            scanf("%lld", &x);
            for(int z=l; z<=r; z++) {
                if(b[gn[z]]==z && e[gn[z]]<=r) {
                    if(gc[gn[z]]) {
                        gfsum[gn[z]] += abs(gc[gn[z]]-x) * (e[gn[z]]-b[gn[z]]+1LL);
                        gf[gn[z]] += abs(gc[gn[z]]-x);
                    } else {
                        for(int k=b[gn[z]]; k<=e[gn[z]]; k++) {
                            if(gc[gn[z]]) c[k] = gc[gn[k]];
                            gfsum[gn[k]] += abs(c[k]-x);
                            f[k] += abs(c[k]-x);
                            c[k] = x;
                        }
                    }
                    gc[gn[z]] = x;
                    z = e[gn[z]];
                } else {
                    if(gc[gn[z]]) {
                        for(int k=b[gn[z]]; k<=e[gn[z]]; k++) c[k] = gc[gn[z]];
                        gc[gn[z]] = 0LL;
                    }
                    gfsum[gn[z]] += abs(c[z]-x);
                    f[z] += abs(c[z]-x);
                    c[z] = x;
                }
            }
        } else {
            long long ans = 0LL;
            for(int z=l; z<=r; z++) {
                if(b[gn[z]]==z && e[gn[z]]<=r) {
                    ans += gfsum[gn[z]];
                    z = e[gn[z]];
                } else ans += gf[gn[z]] + f[z];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
