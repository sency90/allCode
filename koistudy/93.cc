#include <stdio.h>
int v[10001];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i=n-1; i>=0; i--) {
        printf("%d ", v[i]);
    }
    return 0;
}
