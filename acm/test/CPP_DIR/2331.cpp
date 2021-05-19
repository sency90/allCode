#include <stdio.h>
#include <string.h>
int check[236197];
int cnt=0, a, p;
int spow(int x, int y) {
    if(x==0) return 0;
    int res = 1;
    for(char i=0; i<y; i++) res *= x;
    return res;
}
int f(int x) {
    int res = 0, deno;
    for(int i=5; i>=0; i--) {
        deno = spow(10,i);
        res += spow(x/deno,p);
        x %= deno;
    }
    return res;
}
int dfs(int x) {
    if(check[x] != 0) return check[x]-1;
    check[x] = ++cnt;
    return dfs(f(x));
}
int main() {
    scanf("%d %d", &a, &p);
    memset(check, 0, sizeof(check));
    printf("%d", dfs(a));
    return 0;
}
