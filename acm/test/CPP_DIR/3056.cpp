#include <stdio.h>
int n;
double d[1<<20], v[20][20], t;
double f(int x, int s) {
    if(x<0) return 1.0;
    if(d[s]>0) return d[s];
    for(int i=0; i<n; i++) {
        if(s&(1<<i)) {
            t=v[x][i]*f(x-1,s^(1<<i));
            if(t>d[s]) d[s]=t;
        }
    }
    return d[s];
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%lf", &v[i][j]);
            v[i][j]/=100.0;
        }
    }
    printf("%.6lf", f(n-1,(1<<n)-1)*100.0);
    return 0;
}
