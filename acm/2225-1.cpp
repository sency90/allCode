#include<stdio.h>
#define RND 1000000000
int main() {
    int n, k; scanf("%d %d", &n, &k);
    unsigned long long temp = n+1, res=1;
    for(int i=1; i<k; i++) {
        res = (res*temp)%RND;
    }
    printf("%llu", res);
    return 0;
}
