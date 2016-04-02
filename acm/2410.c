#include <stdio.h>
#define RND 1000000000
int d[1000001];
int main() {
    int n; scanf("%d", &n);
    d[0] = 1;
    for(int i=1;i<=n;i++) {
        if(i%2) d[i]=d[i-1];
        else d[i]=(d[i/2]+d[i-1])%RND;
    }
    printf("%d", d[n]);
}
