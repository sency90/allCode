#include <stdio.h>
#include <string.h>
int m[1001], p[1001];
int f( int x ) {
    if( x == 0 ) return 0;
    else if(x == 1) return p[1];
    else if( m[x] == 0 ) {
        int temp;
        for(int i=1; i<x+1; i++) {
            temp = p[i]+f(x-i);
            if(temp > m[x]) m[x] = temp;
        }
    }
    return m[x];
}
int main() {
    memset(m, 0, sizeof(m));
    memset(p, 0, sizeof(p));
    int n; scanf("%d", &n);
    for(int i=1; i<n+1; i++) {
        scanf("%d", &p[i]);
    }
    printf("%d", f(n));
    return 0;
}
