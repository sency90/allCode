#include <stdio.h>
#include <string.h>
int m[1000], p[1000];
int f( int x ) {
    if(x == 0) return p[0];
    else if( m[x] == 0 ) {
        int temp;
        for(int i=0; i<x; i++) {
            temp = f(x-i-1);
            if(m[x] < p[i]+temp) m[x] = p[i]+temp;
        }
    }
    return m[x];
}
int main() {
    memset(m, 0, sizeof(m));
    memset(p, 0, sizeof(p));
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }
    printf("%d", f(n-1));

    return 0;
}
