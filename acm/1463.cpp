#include <stdio.h>
#include <string.h>
#define INF 777777777
#define min(a,b) (a<b?a:b)
int memo[1000001];
int temp, i, p[3];
int f(int x) {
    if(1 == x) return 0; //base case
    else if(0 == x) return INF;

    for(i=0; i<3; i++) p[i] = INF;

    if(0 == (x%3)) {
        if( -1 == memo[x/3] ) memo[x/3] = f(x/3);
        p[0] = memo[x/3] + 1;
    }
    if(0 == (x%2)) {
        if( -1 == memo[x/2] ) memo[x/2] = f(x/2);
        p[1] = memo[x/2] + 1;
    }
    if( -1 == memo[x-1] ) memo[x-1] = f(x-1);
    p[2] = memo[x-1] + 1;

    temp = min(p[0], p[1]);
    return min(temp, p[2]);
}
int main() {
    memset(memo, -1, sizeof(memo));
    int n; scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}
