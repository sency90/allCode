#include <stdio.h>
#include <cstring>
#define RND 1000000007
using namespace std;
int n, l, r, d[101][101][101];
int f(int x, int p, int q) {
    if(d[x][p][q]>0) return d[x][p][q];
    if(p==1 && q==1) {
        if(x==1) return 1;
        else return 0;
    }
    if(p<1 || q<1 || p+q>x+1) return 0;
    return d[x][p][q] = ((long long)(x-2)*f(x-1,p,q) + f(x-1,p-1,q) + f(x-1,p,q-1))%RND;
}
int main() {
    memset(d, 0, sizeof(d));
    scanf("%d %d %d",&n,&l,&r);
    printf("%d", f(n, l, r));
    return 0;
}
