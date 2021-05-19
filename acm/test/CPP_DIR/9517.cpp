#include <stdio.h>
int main() {
    char ans;
    int k, n, s=0, t;
    scanf("%d %d", &k, &n);
    for(int i=1; i<=n; i++) {
        scanf(" %d %c", &t, &ans);
        s += t;
        if(s >= 210) {
            printf("%d", k);
            break;
        }
        if(ans == 'T') k = k%8+1;
    }
}
