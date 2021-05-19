#include <stdio.h>
#include <string.h>
#define RND 1000000
int d[5001], i=0;
char v[5001], c;
int f(int x) {
    if(d[x] > 0) return d[x];
    if(0==x || 1==x) return d[x] = 1;
    if(v[x] >= 1) d[x] = f(x-1);
    if(1==v[x-1] || (2==v[x-1] && v[x]<=6)) d[x] += f(x-2);
    return d[x] %= RND;
}
int main() {
    memset(d, 0, sizeof(d));
    while((c=getchar())!='\n' && c!=EOF) v[++i] = c-48;
    if(v[1]==0) printf("0");
    else printf("%d", f(i));
    return 0;
}
