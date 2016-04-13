#include <stdio.h>
#include <string.h>
unsigned long long cache[90];
unsigned long long f(int x) {
    if( x==0 || x==1 ) return cache[x] = 1; //base case
    cache[x] = ((0 == cache[x-1])? f(x-1) : cache[x-1])  +  ((0 == cache[x-2])? f(x-2) : cache[x-2]);
    return cache[x];
}
int main() {
    memset(cache, 0, sizeof(cache));
    int n; scanf("%d", &n);
    printf("%llu\n", f(n-1));
    return 0;
}
