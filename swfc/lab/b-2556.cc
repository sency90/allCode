#include <stdio.h>
int v[1000001];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        v[x]++;
    }
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int x;
        scanf("%d", &x);
        printf("%d ", v[x]);
    }
    return 0;
}
