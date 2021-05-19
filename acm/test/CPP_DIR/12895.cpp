#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
int v[100000], g[320];
int chg(int s) {
    int cnt = 0;
    while(s!=0) {
        if((s&1)==1) cnt++;
        s = s>>1;
    }
    return cnt;
}
int main() {
    char type[2];
    int n, t, q, x, y, z;
    scanf("%d%d%d",&n,&t,&q);
    int root = (int)sqrt(n);
    for(int i=0; i<n; i++) {
        v[i] = 0;
        g[i/root]=1;
    }
    int xe, ys, gs, ge, s, tmp;
    for(int i=0; i<q; i++) {
        scanf("%s%d%d",type,&x,&y);
        x--; y--;
        xe = (x/root+1)*root-1;
        gs = x/root+1;
        ge = y/root-1;
        ys = y/root;

        if(type[0]=='Q') {
            s = 0;
            for(int j=x; j<=xe; j++) s |= (1<<v[j]);
            for(int j=gs; j<=ge; j++) s |= g[j];
            for(int j=ys; j<=y; j++) s |= (1<<v[j]);
            printf("%d\n", chg(s));
        } else {
            scanf("%d", &z);

            for(int j=x; j<=y; j++) {
                v[j]=z;
            }

            tmp = x/root;
            g[tmp]=0;
            for(int j=tmp*root; j<=xe; j++) {
                g[tmp] |= (1<<v[j]);
            }

            tmp = 1<<z;
            for(int j=gs; j<=ge; j++) {
                g[j] = tmp;
            }

            tmp = y/root;
            g[tmp] = 0;
            for(int j=ys; j<=y; j++) {
                g[tmp] |= (1<<v[j]);
            }
        }
        /*
        printf("%d %d   %d %d   %d %d\n", x,xe,gs,ge,ys,y);
        for(int i=0; i<n; i++) {
            printf("%d ", v[i]);
        }
        puts("");
        */

    }
}
