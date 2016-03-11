#include <stdio.h>
int main() {
    int t, n, m, cnt=0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        cnt = 0;
        for(int i=1; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if((i*i+j*j+m)%(i*j) == 0) {
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
