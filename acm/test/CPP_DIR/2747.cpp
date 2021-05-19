#include <stdio.h>
#include <string.h>
int cache[46];
int f(int n) {
    if(n <= 0) return 0;
    else if(n == 1 || n == 2) return cache[n] = 1;
    if(cache[n] > 0) return cache[n];
    return cache[n] = f(n-1) + f(n-2);
}
int main() {
    memset(cache, 0, sizeof(cache));
    int n; scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}
