#include <stdio.h>
int r[201], p[201], v[201];
int main() {
    int t, n, mxi=0;
    double tmp, mx=0.0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &r[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &p[i]);
            tmp = (double)p[i]/r[i];
            if(tmp-mx>1e-5) {
                mxi = i;
                mx = tmp;
            }
        }

        int m, b;
        if((int)mx == 0) m = r[0];
        else m = ((int)mx+1)*r[0];
        for(int a=0; (p[0]+a)<=m; a++) {
            bool hasAns = true;
            v[0]=a;
            for(int j=1; j<n; j++) {
                if(r[j]*(p[0]+a)%r[0] == 0) {
                    b=r[j]*(p[0]+a)/r[0] - p[j];
                    if(b<0) {
                        hasAns = false; break;
                    } else v[j]=b;
                } else {
                    hasAns = false; break;
                }
            }
            if(hasAns) break;
        }

        for(int i=0; i<n; i++) printf("%d ", v[i]);
        puts("");
    }
    return 0;
}
