#include <stdio.h>
int m,MSB;
int A[3001], B[11], d[2][3001][1024];

inline int max(int x, int y) { return x>y?x:y; }
inline int min(int x, int y) { return x<y?x:y; }
inline int toIdx(int bit) {
    int ret=0;
    for(; bit; bit>>=1, ret++) if(bit&1) return ret;
    return ret; //unreachable code
}
int f(int ps, int n, int bit) {
    if(n==0 && bit==0) {
        return 0;
    }
    int &ret = d[ps][n][bit];
    if(ret>=0) return ret;
    else ret=0;

    if(ps==0) {
        if(n>0) {
            ret = max(ret, f(0,n-1,bit));
            ret = max(ret, f(1,n-1,bit));
        }
        int b=bit, tog=0;
        while(b) {
            tog=b&-b; b^=tog;
            int pbit = bit^tog;
            ret = max(ret, f(0,n,pbit));
            ret = max(ret, f(1,n,pbit));
        }
    } else {
        if(n>0) ret = max(ret, f(0,n-1,bit)+A[n-1]);
        int b=bit, tog=0;
        while(b) {
            tog=b&-b; b^=tog;
            int pbit = bit^tog;
            ret = max(ret, f(0,n,pbit)+B[toIdx(bit&-pbit)]);
        }
    }

    return ret;
}
void init(int n, int m) {
    int lim = 1<<(m+1);
    for(register int i=0; i<=n; i++) {
        for(register int j=0; j<lim; j++) {
            d[0][i][j]=d[1][i][j]=-1;
        }
    }
}
int main() {
    int tc,n; scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &A[i]);
        scanf("%d", &m);
        for(int i=0; i<m; i++) scanf("%d", &B[i]);

        init(n,m);


        printf("%d\n", max(f(0,n,(1<<m)-1), f(1,n,(1<<m)-1)));
    }


    return 0;
}
