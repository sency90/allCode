#include <stdio.h>
int m[26];
int main() {
    int n, k, i, cnt=0, temp;
    scanf("%d %d", &n, &k);
    for(i=1; i*i<n; i++) {
        if(n%i == 0) {
            m[cnt++] = n/i;
            if(cnt == k){
                printf("%d", i);
                return 0;
            }
        }
    }

    if(i*i == n && n%i == 0) {
        m[cnt] = n/i;
        if((temp = 2*cnt+1-k) < 0) printf("0");
        else printf("%d", m[temp]);
    } else {
        if((temp = 2*cnt-k) < 0) printf("0");
        else printf("%d", m[temp]);
    }
    return 0;
}
